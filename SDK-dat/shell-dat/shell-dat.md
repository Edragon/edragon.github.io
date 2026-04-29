
# shell-dat

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