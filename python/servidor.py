# importando o modulo socket
import socket

import datetime

# definindo a porta do servidor
PORTANUMERO = 2102

# criando um socket Internet (INET IPv4) sobre TCP
# AF_INET - Comunicação IP
# SOCK_STREAM - Tráfego confiável (TCP)
# SOCK_DGRAM - Datagrama não confiável (UDP)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# liga o socket ao enderecamento do servidor
s.bind(("", PORTANUMERO))
# s.bind(("127.0.0.1", PORTANUMERO))

# habilita a escuta de conexoes
s.listen(1)

print("Servidor escutando conexoes TCP na porta: %d\n" % PORTANUMERO)

while True:
    # espera por uma conexao
    (clientsocket, clientaddress) = s.accept()

    print("Uma conexao do endereco %s foi estabelecida" % clientaddress[0])

    # aguardando requisicao
    buffer = clientsocket.recv(500)

    # formatando a hora atual
    hora_atual = datetime.datetime.now()
    hora_atual_bytes = hora_atual.strftime("%c").encode("ISO-8859-1")

    print("Enviando a hora atual: %s\n" % hora_atual)

    # enviando a hora pro cliente
    clientsocket.send(hora_atual_bytes)

    # finalizando o socket do cliente
    clientsocket.close()
