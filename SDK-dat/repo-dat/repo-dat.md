
# repo-dat

apt-get install git 


    mkdir -p ~/bin
    curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
    chmod a+x ~/bin/repo
    export PATH=~/bin:$PATH
    source ~/.bashrc

    # Debian/Ubuntu.
    $ sudo apt-get install repo

    # Gentoo.
    $ sudo emerge dev-vcs/repo

国内镜像源安装：

    $ mkdir -p ~/.bin
    $ PATH="${HOME}/.bin:${PATH}"
    $ curl https://mirrors.bfsu.edu.cn/git/git-repo > ~/.bin/repo
    $ chmod a+rx ~/.bin/repo

更换镜像源

Repo 的运行过程中会尝试访问官方的 git 源更新自己，更换镜像源可以提高下载速度。将如下内容复制到你的~/.bashrc 里


    $ echo export REPO_URL='https://mirrors.bfsu.edu.cn/git/git-repo' >> ~/.bashrc
    $ source ~/.bashrc

## error 

    root@ubuntu14:/home/vb# repo --version
    File "/root/bin/repo", line 94
        reexec(f"python{min_major}.{min_minor + inc}")
                                                    ^
    SyntaxError: invalid syntax

because the repo script you downloaded uses Python 3.6+ syntax (f-strings), but Ubuntu 14.04 comes with Python 2.7 and maybe Python 3.4, which are too old to support f-strings.

    rm ~/bin/repo

install legacy version:

    curl -o ~/bin/repo https://storage.googleapis.com/git-repo-downloads/repo-1
    chmod a+x ~/bin/repo


root@ubuntu14:/home/vb# repo --version

    repo version v1.13.11
        (from https://gerrit.googlesource.com/git-repo)
    repo launcher version 1.27
        (from /root/bin/repo)
        (currently at 1.13.11)
    repo User-Agent git-repo/1.13.11 (Linux) git/1.9.1 Python/2.7.6
    git 1.9.1
    git User-Agent git/1.9.1 (Linux) git-repo/1.13.11
    Python 2.7.6 (default, Nov 13 2018, 12:45:42) 
    [GCC 4.8.4]
