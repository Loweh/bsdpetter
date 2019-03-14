#include "socket.h"

int sk_create_server(sk_server *server) { //The listening part of the server will need to check if the linked list is made or not and add the clients accordingly.
    int returnvalue = 0;
    server->clients = NULL;
    
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock == 0) {
        close(server->sock);
        return -1;
    };
    
    int flags = fcntl(server->sock, F_GETFL, 0);
    flags = flags | O_NONBLOCK;
    fcntl(server->sock, F_SETFL, flags);
    
    server->info.sin_addr.s_addr = INADDR_ANY;
    server->info.sin_port = htons(SK_PORT);
    server->info.sin_family = AF_INET;
    
    returnvalue = bind(server->sock, (struct sockaddr *) &server->info, sizeof(server->info));
    if (returnvalue != 0) {
        return -3;
    };
    
    server->alive = 1;
    return 0;
};

int sk_create_client(sk_client *client, char *ip) { //Figure out how to make your clients work non locally.
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
    
    char buffer[2];
    recv(client->sock, buffer, 2, 0);
    client->id = (int) buffer[0];
    
    printf("ID GIVEN: %i\n", client->id);
    
    int flags = fcntl(client->sock, F_GETFL, 0);
    flags = flags | O_NONBLOCK;
    fcntl(client->sock, F_SETFL, flags);
    
    client->alive = 1;
    return 0;
};

int sk_remove_client(sk_client *client) { //Figure out why freeing client makes the program angry.
    close(client->sock);
    
    return 0;
};

int sk_remove_server(sk_server *server) { //Maybe servers should be dynamically allocated?
    close(server->sock);
    ll_remove_list(&(server->clients));
    
    return 0;
};