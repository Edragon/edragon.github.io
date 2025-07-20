
# buildroot-dat

buildroot可用于构建小型的linux根文件系统。

大小最小可低至2M，与内核一起可以放入最小8M的spi flash中。

buildroot中可以方便地加入第三方软件包（其实已经内置了很多），省去了手工交叉编译的烦恼。


    wget https://buildroot.org/downloads/buildroot-2021.02.4.tar.gz
    tar xvf buildroot-2021.02.4.tar.gz
    cd buildroot-2021.02.4/
    
    make menuconfig


编译完成的镜像包，是

    buildroot-2021.02.4/output/images/rootfs.tar

## ref 

- [[F1c100-sdk-dat]]
