# Launch Gollum using a specific git adapter. See https://github.com/gollum/gollum/wiki/Git-adapters
  # Default: rugged
  #
  # Equivalent to --adapter [ADAPTER]

  # Enhanced memory optimization settings
  Gollum::Hook.register(:post_commit, :hook_id) do |committer, sha1|
    # Force garbage collection after commits to prevent memory leaks
    GC.start
    # Also run full GC every 10 commits
    @commit_counter = (@commit_counter || 0) + 1
    GC.start(full_mark: true) if @commit_counter % 10 == 0
  end

  # Memory-efficient middleware configuration
  use Rack::ConditionalGet
  use Rack::ETag
  # Remove Deflater as nginx handles compression

  # Set cache headers for better performance
  class CacheHeaders
    def initialize(app)
      @app = app
    end

    def call(env)
      status, headers, body = @app.call(env)
      
      # Add cache headers for static assets
      if env['PATH_INFO'] =~ /\.(css|js|png|jpg|jpeg|gif|ico|svg|woff|woff2|ttf|eot)$/
        headers['Cache-Control'] = 'public, max-age=86400'
      elsif env['PATH_INFO'] =~ /^\/gollum\/search/
        headers['Cache-Control'] = 'public, max-age=300'
      else
        headers['Cache-Control'] = 'public, max-age=60'
      end
      
      [status, headers, body]
    end
  end

  use CacheHeaders

  # Memory-conscious search configuration - reduced limits for better memory management
  Gollum::Page.class_eval do
    # Limit search results to 50 for better memory usage
    def self.search(repo, query, path = nil)
      results = super(repo, query, path)
      # Limit to first 50 results to reduce memory usage
      results.take(50)
    end
  end

  # Add periodic garbage collection for long-running processes
  Thread.new do
    loop do
      sleep 300  # Every 5 minutes
      GC.start(full_mark: true)
    end
  end

  # Configure Git to be memory efficient
  ENV['GIT_PAGER'] = ''
  ENV['GIT_EDITOR'] = 'true'
  ENV['GIT_CONFIG_NOSYSTEM'] = '1'  # Skip system git config
  ENV['GIT_CONFIG_GLOBAL'] = '/dev/null'  # Skip global git config

  # Use rugged adapter for better memory management
  module Gollum
    Gollum::GIT_ADAPTER = "rugged"
  end

  wiki_options = {

    ##############################################################################
    # Command line option equivalents

    #-----------------------------------------------------------------------------

    #-----------------------------------------------------------------------------
    # Enable file uploads. If set to 'dir', Gollum will store all uploads in the
    # /uploads/ directory in repository root. If set to 'page', Gollum will
    # store each upload at the currently edited page.
    # Default: false

    # Equivalent to --allow-uploads dir
    #allow_uploads: true,

    # Equivalent to --allow-uploads page
    #allow_uploads: true,
    #per_page_uploads: true,

    #-----------------------------------------------------------------------------
    # Set the path to look for static assets.
    #
    # Equivalent to --assets [PATH]

    #static_assets_path: [PATH]

    #-----------------------------------------------------------------------------
    # Tell Gollum that the git repository should be treated as bare.
    #
    # Equivalent to --bare

    #repo_is_bare: true,

    #-----------------------------------------------------------------------------
    # Specify the leading portion of all Gollum URLs (path info). Setting this to
    # /wiki will make the wiki accessible under http://localhost:4567/wiki/.
    # Default: /
    #
    # Equivalent to --base-path [PATH]

    #base_path: [PATH],

    #-----------------------------------------------------------------------------
    # Enable support for annotations using CriticMarkup.
    #
    # Equivalent to --critic-markup

    #critic_markup: true,

    #-----------------------------------------------------------------------------
    # Tell Gollum to inject custom CSS into each page. Uses custom.css from wiki
    # root
    #
    # Equivalent to --css

    #css: true,

    #-----------------------------------------------------------------------------
    # Parse and interpret emoji tags (e.g. :heart:) except when the leading colon
    # is backslashed (e.g. \:heart:).
    #
    # Equivalent to --emoji

    #emoji: true,

    #-----------------------------------------------------------------------------
    # Tell Gollum to use the first <h1> as page title.
    #
    # Equivalent to --h1-title

    h1_title: true,

    #-----------------------------------------------------------------------------
    # Specify the hostname or IP address to listen on.
    # Default: '0.0.0.0'.
    #
    # Equivalent to --host [HOST]

    # ???

    #-----------------------------------------------------------------------------
    # Launch Gollum in "console mode", with a predefined API.
    #
    # Equivalent to --irb

    # ???

    #-----------------------------------------------------------------------------
    # Tell Gollum to inject custom JS into each page. Uses custom.js from wiki
    # root.
    #
    # Equivalent to --js

    #js: true,

    #-----------------------------------------------------------------------------
    # Compatibility with 4.x
    # https://github.com/gollum/gollum/wiki/5.0-release-notes#compatibility-option
    #
    # Internal links resolve case-insensitively, will treat spaces as hyphens, and
    # will match the first page found with a certain filename, anywhere in the
    # repository. Provides compatibility with Gollum 4.x.
    #
    # Equivalent to --lenient-tag-lookup

    hyphened_tag_lookup: true,
    case_insensitive_tag_lookup: true,
    global_tag_lookup: true,

    #-----------------------------------------------------------------------------
    # Enables MathJax (renders mathematical equations). By default, uses the
    # TeX-AMS-MML_HTMLorMML config with the autoload-all extension.5
    #
    # Equivalent to --mathjax

    #mathjax: true,

    #-----------------------------------------------------------------------------
    # Specify path to a custom MathJax configuration.
    # Default: mathjax.config.js file from repository root.
    #
    # Equivalent to --mathjax-config [FILE]

    #mathjax_config: [FILE],

    #-----------------------------------------------------------------------------
    # Do not render metadata tables in pages.
    #
    # Equivalent to --no-display-metadata

    #display_metadata: false,

    #-----------------------------------------------------------------------------
    # Disable the feature of editing pages.
    # Default: true
    #
    # Equivalent to --no-edit

    allow_editing: false,

    #-----------------------------------------------------------------------------
    # Specify the subdirectory for all pages. If set, Gollum will only serve pages
    # from this directory and its subdirectories.
    # Default: repository root.
    #
    # Equivalent to --page-file-dir [PATH]

    #page_file_dir: [PATH],

    #-----------------------------------------------------------------------------
    # Follow pages across renames in the History view.
    # Default: true.

    # Equivalent to --follow-renames
    #follow_renames: true,

    # Equivalent to --no-follow-renames
    #follow_renames: false,

    #-----------------------------------------------------------------------------
    # Specify the port to bind Gollum with.
    # Default: 4567.
    #
    # Equivalent to --port [PORT]

    # ???

    #-----------------------------------------------------------------------------
    # Specify the git branch to serve.
    # Default: master.
    #
    # Equivalent to --ref [REF]

    #ref: [REF],

    #-----------------------------------------------------------------------------
    # Use static assets.
    # Defaults to false in development/test, true in
    # production/staging.

    # Equivalent to --static
    #static: true,

    # Equivalent to --no-static
    #static: false,

    #-----------------------------------------------------------------------------
    # Specify custom mustache template directory.
    #
    # Equivalent to --template-dir [PATH]

    template_dir: '/root/edragon.github.io/gollum',

    #-----------------------------------------------------------------------------
    # Use _Template in root as a template for new pages. Must be committed.
    #
    # Equivalent to --template-page

    #template_page: true,

    #-----------------------------------------------------------------------------
    # Tell Gollum to use specific user icons for history view. Can be set to
    # gravatar, identicon or none.
    # Default: none.
    #
    # Equivalent to --user-icons [MODE]

    #user_icons: [MODE],

    ##############################################################################
    # Metadata (front matter)

    #-----------------------------------------------------------------------------
    # Header counting
    # Default: false
    # Can also be a pre-defined counter. See
    # https://www.w3.org/TR/css-counter-styles-3/#predefined-counters

    #header_enum: false,
    #header_enum: 'decimal-leading-zero',

    #-----------------------------------------------------------------------------
    # Global metadata. Arbitrary metadata that will be applied to each page.

    #metadata: {
    #  monkeyboys: 'are loose in the facility'
    #},

    ##############################################################################
    # Tips

    #-----------------------------------------------------------------------------
    # Force table of contents tag ([[_TOC_]]) into each page.
    # ??? How to set the level in the configuration file?
    # https://github.com/gollum/gollum/wiki#table-of-contents-toc-tag
    # Default: false

    #universal_toc: false,

    #-----------------------------------------------------------------------------
    # Move the sidebar to the left of the page
    # https://github.com/gollum/gollum/issues/1450#issuecomment-599124384

    #sidebar: :left,

    #-----------------------------------------------------------------------------
    # Change the home page name
    # https://github.com/gollum/gollum/issues/1569#issuecomment-633033895

    #index_page: 'index',

    #-----------------------------------------------------------------------------
    # Change the number of changes in the rss feed
    # Reduced for memory efficiency

    pagination_count: 10,
    
    #-----------------------------------------------------------------------------
    # Additional memory optimization settings
    
    # Disable features that consume memory
    follow_renames: false,
    display_metadata: false,
    
    # Enable memory-efficient caching
    cache_enabled: true
  }

  #-------------------------------------------------------------------------------
  # Change default markup
  #Precious::App.set(:default_markup, :asciidoc)

  Precious::App.set(:wiki_options, wiki_options)

# EMERGENCY MEMORY OPTIMIZATION for 2GB systems

# Force aggressive garbage collection
class MemoryManager
  def self.setup
    # Force GC every 50 requests
    @request_count = 0
    
    # Hook into Rack to trigger GC
    Rack::Builder.new do |builder|
      builder.use Rack::Runtime
      builder.use Class.new do
        def initialize(app)
          @app = app
        end
        
        def call(env)
          @request_count = (@request_count || 0) + 1
          
          # Force GC every 50 requests
          if @request_count % 50 == 0
            GC.start(full_mark: true)
            @request_count = 0
          end
          
          @app.call(env)
        end
      end
    end
  end
end

MemoryManager.setup

# Extremely aggressive GC thread
Thread.new do
  loop do
    sleep 120  # Every 2 minutes
    GC.start(full_mark: true)
    GC.compact if GC.respond_to?(:compact)
  end
end

# Limit search results drastically
Gollum::Page.class_eval do
  def self.search(repo, query, path = nil)
    results = super(repo, query, path)
    results.take(20)  # Only 20 results max
  end
end

# Memory-efficient Git configuration
ENV['GIT_PAGER'] = ''
ENV['GIT_EDITOR'] = 'true'
ENV['GIT_CONFIG_NOSYSTEM'] = '1'
ENV['GIT_CONFIG_GLOBAL'] = '/dev/null'

# Use rugged adapter
module Gollum
  Gollum::GIT_ADAPTER = "rugged"
end

wiki_options = {
  h1_title: true,
  hyphened_tag_lookup: true,
  case_insensitive_tag_lookup: true,
  global_tag_lookup: true,
  allow_editing: false,
  template_dir: '/root/edragon.github.io/gollum',
  
  # EXTREME memory conservation
  pagination_count: 5,  # Reduced from 10
  follow_renames: false,
  display_metadata: false,
  cache_enabled: false,  # Disable caching to save memory
  
  # Disable expensive features
  emoji: false,
  mathjax: false,
  css: false,
  js: false
}

Precious::App.set(:wiki_options, wiki_options)
