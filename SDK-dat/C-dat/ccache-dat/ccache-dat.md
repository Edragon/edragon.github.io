
# ccache-dat

Install ccache:

    sudo apt install ccache         # Debian/Ubuntu
    brew install ccache             # macOS

ESP-IDF supports `ccache` to avoid recompiling unchanged files.

### Enable it:

    export IDF_CCACHE_ENABLE=1

Or add to your ~/.bashrc / ~/.zshrc:

    export IDF_CCACHE_ENABLE=1



## ref 

- [[c-dat]] - [[esp-idf-dat]]