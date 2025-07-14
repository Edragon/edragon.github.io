
# ubuntu-dat.md

![](2025-07-14-23-09-16.png)

![](2025-07-14-23-09-43.png)


## share folder 

![](2025-07-14-23-10-07.png)

- 打开终端 (Open the terminal).
- 使用命令 cd /mnt 进入到 mnt 目录 (Use the command cd /mnt to enter the mnt directory).
- 使用命令 sudo mkdir share 创建 share 文件夹 (Use the command sudo mkdir share to create the share folder).
- 使用命令 sudo mount -t vboxsf share /mnt/share 挂载共享文件夹 (Use the command sudo mount -t vboxsf share /mnt/share to mount the shared folder).
- 进入到 share 目录 (Enter the share directory).
- 使用 ls 命令查看挂载结果 (Use the ls command to check the mounted folder).

## ref 

- [[virtualbox-dat]]