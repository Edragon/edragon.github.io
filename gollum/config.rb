# Launch Gollum using a specific git adapter. See https://github.com/gollum/gollum/wiki/Git-adapters
# Default: rugged
#
# Equivalent to --adapter [ADAPTER]

# Basic Gollum configuration

# Use rugged adapter for better performance

# 
module Gollum
  Gollum::GIT_ADAPTER = "rugged"
end

wiki_options = {
  # Basic settings
  h1_title: true,
  allow_editing: false,
  hyphened_tag_lookup: true,
  case_insensitive_tag_lookup: true,
  global_tag_lookup: true,
  pagination_count: 5,
  template_dir: '/var/edragon.github.io/gollum/templates',
  
  # Performance optimizations
  # show_all: false,           # Don't show all files by default
  # collapse_tree: false,      # Don't expand tree by default
  # per_page_limit: 10,        # Limit files per page
  # history_limit: 20,         # Limit history entries
  # mathjax: false,           # Disable MathJax if not needed
  # live_preview: false,      # Disable live preview
  
  # Git optimizations
  # repo_is_bare: false,
  ref: 'master'               # Use specific branch instead of scanning all
}

Precious::App.set(:wiki_options, wiki_options)

# Increase worker processes for better performance
Gollum::Hook.register(:post_commit, :hook_id) do |committer, sha1|
  # Add any post-commit hooks here
end

