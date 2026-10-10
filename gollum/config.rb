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
  h1_title: true,
  allow_editing: false,

  # 不关闭昂贵的全局标签查找（12k 文件上代价极高）
  global_tag_lookup: true,
  hyphened_tag_lookup: true,
  case_insensitive_tag_lookup: true,

  pagination_count: 5,
  template_dir: '/var/edragon.github.io/gollum/templates',

  # 启用被注释掉的性能选项
  show_all: false,
  collapse_tree: true,
  per_page_limit: 10,
  history_limit: 20,
  mathjax: false,
  live_preview: false,

  ref: 'master'
}

Precious::App.set(:wiki_options, wiki_options)

# Increase worker processes for better performance
Gollum::Hook.register(:post_commit, :hook_id) do |committer, sha1|
  # Add any post-commit hooks here
end
