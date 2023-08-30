# Hora Certa
Código de exemplo de serviço de HoraCerta com sockets.

## Código em C

Compilando e executando código do servidor:

```
$ gcc servidor.c -o servidor
$ ./servidor
Servidor escutando conexões na porta: 2343
```

Compilando e executando código do cliente:

```
$ gcc cliente.c -o cliente
$ ./cliente
Hora certa: Thu Mar  4 16:35:00 2010
```

## Código em Python

Executando o servidor:

```
$ python3 servidor.py
Servidor escutando conexões na porta: 2343
```

Executando o cliente:

```
$ python3 cliente.py
Hora certa: Thu Mar  4 16:35:00 2010
```
