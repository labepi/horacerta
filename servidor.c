#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORTANUMERO 2343

int main(int argc, char* argv[])
{
    char buffer[100];

    // recebe o tamanho da estrutura sockaddr_in
    int sockettamanho;
    
    // descritor do socket da escuta
    int meusocket;
    
    // descritor do socket da conexao
    int socketconexao;
    
    // informacoes do cliente
    struct sockaddr_in endereco_cliente;
    
    // informacoes do servidor
    struct sockaddr_in endereco_servidor;
    
    // armazenara a hora
    time_t ticks;
    
    // tamanho da estrutura de endereco do skcet usado
    sockettamanho = sizeof(struct sockaddr_in);

    // AF_INET - Comunicação IP
    // SOCK_STREAM - Tráfego confiável (TCP)
    // SOCK_DGRAM - Datagrama não confiável (UDP)
    meusocket = socket(AF_INET, SOCK_STREAM, 0);
    
    endereco_servidor.sin_family = AF_INET;
    
    // define qualquer ip da interface de rede
    endereco_servidor.sin_addr.s_addr = INADDR_ANY;
    
    // define a porta de escuta do servidor
    endereco_servidor.sin_port = htons(PORTANUMERO);
    
    // zera o resto da estrutura
    memset(&(endereco_servidor.sin_zero), '\0', sizeof(endereco_servidor.sin_zero));
    
    // liga o socket ao enderecamento do servidor
    bind(meusocket, (struct sockaddr *)&endereco_servidor, sizeof(struct sockaddr));
    
    // habilita a escuta de conexoes
    listen(meusocket, 1);
    
    printf("Servidor escutando conexoes TCP na porta: %d\n",PORTANUMERO);

    while(1)
    {
        //espera por uma conexao
        socketconexao = accept(meusocket, (struct sockaddr *)&endereco_cliente, &sockettamanho);
        printf("Uma conexao do endereco %s foi estabelecida - informando a hora certa\n", inet_ntoa(endereco_cliente.sin_addr));
        ticks = time(NULL);
        snprintf(buffer, sizeof(buffer), "%.24s ", ctime(&ticks));
        send(socketconexao, buffer, strlen(buffer), 0);
        close(socketconexao);
    }

    close(meusocket);
    
    return 0;

}

// Instrucoes de compilacao
// gcc servidor.c -o servidor
