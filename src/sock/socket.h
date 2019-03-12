#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include "../util/l_list.h"

//sk is for socket.

#define SK_PORT 2127

typedef struct {
    struct sockaddr_in server;
    int sock, id, alive;
} sk_client;

typedef struct {
    ll_node *clients;
    struct sockaddr_in info;
    int sock, alive;
} sk_server;

int sk_create_server(sk_server *server);
int sk_create_client(sk_client *client, char* ip);

int sk_remove_server(sk_server *server);
int sk_remove_client(sk_client *client);

#endif
