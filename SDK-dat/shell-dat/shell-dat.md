
# shell-dat


## winget install DeviceTreeCompiler

winget search DeviceTreeCompiler

winget install MSYS2.MSYS2

    # Update the package database
    pacman -Syu

    # Install the Device Tree Compiler (DTC)
    pacman -S mingw-w64-x86_64-dtc

Add MSYS2 to your Windows PATH: C:\msys64\mingw64\bin

## winget install Ninja-build.Ninja

## winget install 7zip.7zip

winget search 7z

PS C:\Users\Administrator> winget search 7z
Name                                 Id                        Version            Match       Source
-----------------------------------------------------------------------------------------------------
Zip Unzip - rar,&7z compression      9MT44RNLPXXT              Unknown                        msstore
Total Zip: Rar, Zip and 7Z Extractor 9MT1HPWLNJ0C              Unknown                        msstore
7-Zip                                7zip.7zip                 26.01              Command: 7z winget
7-Zip ZS                             mcmilk.7zip-zstd          25.01 ZS v1.5.7 R4 Command: 7z winget
7-Zip ZS Non Darkmode                mcmilk.7zip-zstd-ndm      25.01 ZS v1.5.7 R4 Command: 7z winget
7zr                                  7zip.7zr                  26.00                          winget
Advanced Archive Password Recovery   Elcomsoft.ArchivePassword 4.66.266.6965      Tag: 7zip   winget
NanaZip                              M2Team.NanaZip            6.0.1701.0         Tag: 7zip   winget
NanaZip Preview                      M2Team.NanaZip.Preview    6.5.1638.0         Tag: 7zip   winget
QNapi                                QNapi.QNapi               0.2.3              Tag: p7zip  winget

also set $env:Path += ";C:\Program Files\7-Zip"

## winget install GNU.Wget

PS C:\Users\Administrator> winget search wget
Name  Id                  Version Match     Source
--------------------------------------------------
Wget  JernejSimoncic.Wget 1.21.4            winget
Wget2 GNU.Wget2           2.2.1   Tag: wget winget

winget install JernejSimoncic.Wget


## powershell 

(Invoke-WebRequest -Uri "https://api.ipify.org").Content

notepad $PROFILE

    $env:HTTP_PROXY = "http://127.0.0.1:7897"
    $env:HTTPS_PROXY = "http://127.0.0.1:7897"

Get-ChildItem Env: | Where-Object { $_.Name -match "PROXY" }

System Proxy Toggle: Ensure the `System Proxy` switch is ON in the Clash Verge dashboard.

## bash 

nano ~/.bashrc

# Clash Verge Proxy Toggle
function proxy_on() {
    export http_proxy="http://127.0.0.1:7897"
    export https_proxy="http://127.0.0.1:7897"
    export all_proxy="socks5://127.0.0.1:7897"
    export no_proxy="localhost,127.0.0.1,localaddress,.localdomain.com"
    echo "Proxy environment variables set."
}

function proxy_off() {
    unset http_proxy https_proxy all_proxy no_proxy
    echo "Proxy environment variables cleared."
}

source ~/.bashrc

curl -L ip.gs

curl -I https://www.google.com

Success: If you see HTTP/2 200 or HTTP/1.1 200 OK, your proxy is working, and the firewall is bypassed.

Failure: If the terminal hangs (times out) or returns Connection refused, the proxy environment variables are not set correctly or Clash is not running.

Proxy-specific error: If you get a 500 or 502 error, Clash is reachable, but your selected proxy node (server) might be down.