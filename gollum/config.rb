# Launch Gollum using a specific git adapter. See https://github.com/gollum/gollum/wiki/Git-adapters
# Default: rugged
#
# Equivalent to --adapter [ADAPTER]

# EMERGENCY MEMORY OPTIMIZATION for 2GB systems

# Enhanced memory optimization settings
Gollum::Hook.register(:post_commit, :hook_id) do |committer, sha1|
  # Force garbage collection after commits to prevent memory leaks
  GC.start
  # Also run full GC every 5 commits for aggressive memory management
  @commit_counter = (@commit_counter || 0) + 1
  GC.start(full_mark: true) if @commit_counter % 5 == 0
end

# Memory-efficient middleware configuration
use Rack::ConditionalGet
use Rack::ETag
# Remove Deflater as nginx handles compression

# Force aggressive garbage collection every 20 requests
class MemoryManager
  @@request_count = 0
  
  def initialize(app)
    @app = app
  end
  
  def call(env)
    @@request_count += 1
    
    # Force GC every 20 requests for extreme memory control
    if @@request_count % 20 == 0
      GC.start(full_mark: true)
      GC.compact if GC.respond_to?(:compact)
      @@request_count = 0
    end
    
    @app.call(env)
  end
end

use MemoryManager

# Extremely aggressive GC thread
Thread.new do
  loop do
    sleep 60  # Every 1 minute
    GC.start(full_mark: true)
    GC.compact if GC.respond_to?(:compact)
  end
end

# Limit search results drastically for memory conservation
Gollum::Page.class_eval do
  def self.search(repo, query, path = nil)
    results = super(repo, query, path)
    results.take(15)  # Only 15 results max
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
    # Basic settings
    h1_title: true,
    hyphened_tag_lookup: true,
    case_insensitive_tag_lookup: true,
    global_tag_lookup: true,
    allow_editing: false,
    template_dir: '/root/edragon.github.io/gollum',
    
    # EXTREME memory conservation settings
    pagination_count: 5,  # Very small pagination
    follow_renames: false,
    display_metadata: false,
    cache_enabled: false,  # Disable caching to save memory
    
    # Disable ALL expensive features for maximum memory savings
    emoji: false,
    mathjax: false,
    css: false,
    js: false,
    critic_markup: false
  }

  #-------------------------------------------------------------------------------
  # Change default markup
  #Precious::App.set(:default_markup, :asciidoc)

  Precious::App.set(:wiki_options, wiki_options)
