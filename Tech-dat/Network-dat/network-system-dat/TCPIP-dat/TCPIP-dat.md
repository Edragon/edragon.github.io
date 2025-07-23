
# TCPIP-dat


## tools 

### 1. Netcat (nc) == Cross-platform or Windows
- Type: Command-line
- Supports: TCP and UDP
- Platforms: Linux, macOS, Windows (via `ncat`)

Example (TCP listener):

    nc -l -p 5000

Example (send TCP):

    echo "Hello" | nc 127.0.0.1 5000

## TCP server python script 

    # tcp_server.py
    import socket

    HOST = '0.0.0.0'  # Listen on all interfaces
    PORT = 5000       # Change as needed

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen()

    print(f"Listening on {HOST}:{PORT}...")

    conn, addr = server_socket.accept()
    print(f"Connected by {addr}")

    while True:
        data = conn.recv(1024)
        if not data:
            break
        print("Received:", data.decode())
        conn.sendall(b'ACK: ' + data)  # Send back confirmation

    conn.close()

