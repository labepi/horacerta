#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXIMOMSG 500

/**
 * programa cliente
 */
int main(int argc, char *argv[])
{
    char buffer[MAXIMOMSG + 1]; // para incluir o terminador nulo
    int tamanho, meusocket;
    struct sockaddr_in destinatario;

    meusocket = socket(AF_INET, SOCK_STREAM, 0);

    destinatario.sin_family = AF_INET;

    // ip do servidor - 127.0.0.1 se estiver rodando na sua mesma maquina
    destinatario.sin_addr.s_addr = inet_addr("127.0.0.1");

    // porta do servidor
    destinatario.sin_port = htons(2343);

    // zerando o resto da estrutura
    memset(&(destinatario.sin_zero), '\0', sizeof(destinatario.sin_zero));

    connect(meusocket, (struct sockaddr *)&destinatario, sizeof(struct sockaddr));

    tamanho = recv(meusocket, buffer, MAXIMOMSG, 0);

    // terminando a mensagem
    buffer[tamanho] = '\0';

    printf("Hora certa: %s\n", buffer);

    // termina o socket
    close(meusocket);

    return 0;
} 

// Instrucoes para compilacao
// gcc cliente.c -o cliente

