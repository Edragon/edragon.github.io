
# virtualbox-dat

## supported SDK 

- [[TINA-dat]]

- [[C-dat]]


## install 

下载安装
官网下载地址：https://www.virtualbox.org/

参考链接： Oracle VM VirtualBox官网下载安装教程： https://blog.csdn.net/kaixuansui/article/details/89334859/

VirtualBox安装Ubuntu
注意：

(1)内存大小设置：建议大于2GB
(2) 虚拟硬盘大小设置：建议至少设置50GB（SDK所需较大空间）
(3) 安装好Ubuntu14.04虚拟机环境后，建议不要在线升级Ubuntu版本

参考链接： Oracle VM VirtualBox安装Ubuntu14.04环境的教程： https://blog.csdn.net/weixin_42135087/article/details/108193641

## 增强功能

安装增强功能可以实现共享剪切板功能共享文件夹功能。共享粘贴板可在PC和虚拟机之间互相粘贴复制内容。文件夹共享可以在本地主机下创建一个文件夹，然后VirtualBOX将该文件夹映射到虚拟机下指定的文件夹中，这样我们就可以访问该文件夹下的子文件夹以及文件了。这两个功能都能极大地提高我们的开发效率

注意： 在共享文件夹的路径中如果是挂在的windows系统的文件夹，可能无法成功地下载Tina的SDK代码，注意SDK的下载目录不要设置在共享文件夹中。

### 安装增强功能的方法

方法一： 点击虚拟机界面上面菜单栏的【设备】--【安装增强功能】。然后可以看到在虚拟机的光驱中自动加载了增强iso的文件(VBoxGuestAdditions.iso)，点击【Run】运行按钮。接着按虚拟机所指引步骤进行即可。

方法二： 在linux中挂载光驱。参考链接如下： https://jingyan.baidu.com/article/fdbd42779d9530b89e3f489c.html

实现共享文件夹的方：

在VirtualBox中创建共享文件夹的参考链接如下： http://www.koudaipe.com/funny/1002.html

共享文件夹 共享文件夹后可能由于权限问题无法操作，需要做如下操作：


sudo usermod -aG vboxsf $(whoami)
*$(whoami) 替换成您Ubuntu的用户名

## virtualbox setup guide 

- preference
    - set global file location 

### proxy 

preferences -> network -> proxy == socks5://127.0.0.1:7897

- turn on TUN mode



# VirtualBox Guide

## Installation

- Official download: [https://www.virtualbox.org/](https://www.virtualbox.org/)
- Reference: [Oracle VM VirtualBox Official Installation Tutorial (Chinese)](https://blog.csdn.net/kaixuansui/article/details/89334859/)

https://download.virtualbox.org/virtualbox/7.1.10/VirtualBox-7.1.10-169112-Win.exe

## Installing Ubuntu in VirtualBox

**Tips:**

1. **Memory Size:** Set to more than 2GB (recommended)
2. **Virtual Hard Disk Size:** At least 50GB (SDK requires large space)
3. **Do not upgrade Ubuntu online** after installing Ubuntu 14.04 in the VM

- Reference: [Oracle VM VirtualBox Ubuntu 14.04 Setup Tutorial (Chinese)](https://blog.csdn.net/weixin_42135087/article/details/108193641)

- 现在创建虚拟硬盘（C）
- VDI (VirtualBox磁盘映像）
- 动态分配（D）
- Choose a disk file...
- ubuntu-14.04-desktop-amd64.iso

- [[ubuntu-dat]]

## Guest Additions (Enhancements)

Installing Guest Additions enables:
- Shared clipboard (copy/paste between PC and VM)
- Shared folders (map a host folder to the VM for easy file access)

These features greatly improve development efficiency.

**Note:**
If the shared folder is a Windows folder, you may not be able to successfully download Tina SDK code into it. Avoid setting the SDK download directory inside a shared folder.

### How to Install Guest Additions

**Method 1:**
1. In the VM window, go to the menu bar: `Devices` → `Insert Guest Additions CD image...`
2. The ISO (VBoxGuestAdditions.iso) will auto-mount in the VM's CD drive.
3. Click `Run` and follow the on-screen instructions.

**Method 2:**
1. Manually mount the CD drive in Linux.
2. Reference: [Linux Mount CD Drive Tutorial (Chinese)](https://jingyan.baidu.com/article/fdbd42779d9530b89e3f489c.html)

## Setting Up Shared Folders

- Reference: [How to Create Shared Folders in VirtualBox (Chinese)](http://www.koudaipe.com/funny/1002.html)

**Permissions Fix:**
If you cannot access the shared folder due to permissions, run:

```bash
sudo usermod -aG vboxsf $(whoami)
# Replace $(whoami) with your Ubuntu username if needed
```

    sudo usermod -aG vboxsf vb
    reboot 



## root 

    su 
    usermod -aG sudo vb



## common error 

-  Use VBoxVGA Display Controller (Fix for Older Ubuntu)




## usage

### scale mode 

The virtual machine window will be now switched to Scale mode. You can go back to windowed mode at any time by pressing Host+C. Note that the Host key is currently defined as Right Ctrl.

Note that the main menu bar is hidden in scaled mode. You can access it by pressing Host+Home.

## system immgration 

- re-set share folder 



## ref 

