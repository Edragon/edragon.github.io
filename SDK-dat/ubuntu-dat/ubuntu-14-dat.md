
# ubuntu-14-dat.md

Ubuntu 14 is **very old** (GCC 4.8 by default), and newer GCC versions may be more tolerant. Consider:

```bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install gcc-7 g++-7
export CC=gcc-7
make clean && make
```

## ref 

- [[ubuntu-dat]]
