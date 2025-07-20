
#设置编译链路径及工具
CTOOL := riscv64-unknown-linux-gnu-
CCL := /home/kunyao/workspace/d_tina_d1_open_v1.0/prebuilt/gcc/linux-x86/riscv/toolchain-thead-glibc/riscv64-glibc-gcc-thead_20200702
CC := ${CCL}/bin/${CTOOL}gcc

#设置编译规则
hello_word:hello_word.c
    ${CC} -o hello_word hello_word.c

#清理规则
clean:
    rm hello_word