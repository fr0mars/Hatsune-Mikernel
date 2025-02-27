
import socket
import base64


def start_c2_server():

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("127.0.0.1", 4444))
    server.listen(1)

    conn = server.accept()

    cmd = base64.b64encode("status").decode()
    conn.send(cmd.encode())

    response = conn.recv(4096).decode()
    response = (base64.b64decode(response))
    print(response)

    conn.close()
    server.close()

if __name__ == "__main__":
    start_c2_server()