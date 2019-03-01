#include "socket.h"

int sk_create_server(sk_server *server, char *port) {
    return 0;
};

int sk_create_client(sk_client *client, char *ip) {
    int returnvalue = 0;
    client = malloc(sizeof(sk_client));
    
    client->id = 0;
    client->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock == 0) {
        close(client->sock);
        return -1;
    };
    
    client->server.sin_addr.s_addr = inet_addr(ip);
    client->server.sin_port = htons(SK_PORT);
    client->server.sin_family = AF_INET;    
    
    returnvalue = connect(client->sock, (struct sockaddr *) &client->server, sizeof(client->server));
    if (returnvalue < 0) {
        close(client->sock);
        return -2;
    };
    
    close(client->sock);
    return 0;
};