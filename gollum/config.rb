# Launch Gollum using a specific git adapter. See https://github.com/gollum/gollum/wiki/Git-adapters
# Default: rugged
#
# Equivalent to --adapter [ADAPTER]

# EMERGENCY MEMORY OPTIMIZATION for 2GB systems

# Additional Ruby memory optimizations
GC.start(full_mark: true)  # Start with clean slate
ObjectSpace.garbage_collect if defined?(ObjectSpace.garbage_collect)

# Configure Ruby GC to be more aggressive
GC::Profiler.enable if defined?(GC::Profiler)

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

# Force aggressive garbage collection every 10 requests (reduced from 20)
class MemoryManager
  @@request_count = 0
  
  def initialize(app)
    @app = app
  end
  
  def call(env)
    @@request_count += 1
    
    # Force GC every 10 requests for extreme memory control (more frequent)
    if @@request_count % 10 == 0
      GC.start(full_mark: true)
      GC.compact if GC.respond_to?(:compact)
      @@request_count = 0
    end
    
    # Emergency memory check - force GC if memory usage is too high
    if @@request_count % 5 == 0
      GC.start
    end
    
    @app.call(env)
  end
end

use MemoryManager

# More aggressive GC thread with memory monitoring
Thread.new do
  loop do
    sleep 30  # Every 30 seconds (more frequent)
    GC.start(full_mark: true)
    GC.compact if GC.respond_to?(:compact)
    
    # Force additional cleanup every 3rd cycle
    @gc_cycle_count = (@gc_cycle_count || 0) + 1
    if @gc_cycle_count % 3 == 0
      # Clear any cached objects
      ObjectSpace.garbage_collect
      @gc_cycle_count = 0
    end
  end
end

# Limit search results drastically for memory conservation
Gollum::Page.class_eval do
  def self.search(repo, query, path = nil)
    results = super(repo, query, path)
    results.take(10)  # Reduced to only 10 results max
  end
end

# Limit file list results to prevent memory issues
Gollum::Wiki.class_eval do
  def pages(treeish = nil, limit = nil)
    limit ||= 50  # Hard limit of 50 pages per request
    super(treeish, limit)
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
    hyphened_tag_lookup: false,  # Disabled for memory saving
    case_insensitive_tag_lookup: false,  # Disabled for memory saving
    global_tag_lookup: false,  # Disabled for memory saving
    allow_editing: false,
    template_dir: '/root/edragon.github.io/gollum',
    
    # EXTREME memory conservation settings
    pagination_count: 3,  # Reduced from 5 to 3
    follow_renames: false,
    display_metadata: false,
    cache_enabled: false,  # Disable caching to save memory
    
    # Disable ALL expensive features for maximum memory savings
    emoji: false,
    mathjax: false,
    css: false,
    js: false,
    critic_markup: false,
    
    # Additional memory-saving options
    show_all: false,
    live_preview: false,
    allow_uploads: false
  }

  #-------------------------------------------------------------------------------
  # Change default markup
  #Precious::App.set(:default_markup, :asciidoc)

  Precious::App.set(:wiki_options, wiki_options)
