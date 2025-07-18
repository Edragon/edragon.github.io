# Launch Gollum using a specific git adapter. See https://github.com/gollum/gollum/wiki/Git-adapters
# Default: rugged
#
# Equivalent to --adapter [ADAPTER]

# Basic Gollum configuration

# Use rugged adapter for better performance
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
  template_dir: '/root/edragon.github.io/gollum'


}

Precious::App.set(:wiki_options, wiki_options)
