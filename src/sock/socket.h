#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "../util/l_list.h"

//sk is for socket.

#define SK_PORT 2127

typedef struct {
    struct sockaddr_in server;
    int sock, id;
} sk_client;

typedef struct {
    ll_node *clients;
    //struct addrinfo hints;
    int sock, last_val;
} sk_server;

int sk_create_server(sk_server *server, char *port);
int sk_create_client(sk_client *client, char* ip);

#endif
