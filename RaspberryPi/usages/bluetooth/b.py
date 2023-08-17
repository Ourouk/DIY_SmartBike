import bluetooth

target_address = "4C:EA:AE:B3:D9:CC"  # Replace with your phone's Bluetooth address

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect((target_address, 2))  # Channel 1 is typically used for RFCOMM

data = "Hello, phone!"
sock.send(data.encode())  # Convert the data to bytes before sending

sock.close()
print("Data sent:", data)
'''

 script serveur 

'''

import bluetooth

server_sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
server_sock.bind(("", bluetooth.PORT_ANY))
server_sock.listen(1)

port = server_sock.getsockname()[1]

print("Waiting for connection on RFCOMM channel", port)

client_sock, client_info = server_sock.accept()
print("Accepted connection from", client_info)

try:
    while True:
        data = client_sock.recv(1024)
        if not data:
            break
        print("Received:", data.decode())
        client_sock.send("Message received: ".encode() + data)
except OSError:
    pass

print("Disconnected.")

client_sock.close()
server_sock.close()
print("All done.")