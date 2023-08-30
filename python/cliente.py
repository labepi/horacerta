# importando o modulo socket
import socket

# definindo o IP do servidor
IP = "127.0.0.1"

# definindo a porta do servidor
PORTANUMERO = 2343

# criando um socket Internet (INET IPv4) sobre TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# conectando ao servidor
s.connect((IP, PORTANUMERO))

# recebendo a hora do servidor
buffer = s.recv(500)

# imprimindo a hora recebida
print("Hora certa: %s" % buffer.decode("ISO-8859-1"))

# fechando o socket
s.close()
