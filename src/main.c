#include "util/l_list.h"
#include "sock/socket.h"

/*
Compiling this thing is already a pain so just remember this:

gcc main.c util/l_list.c sock/socket.c -o ../output/test -std=c99 -w

Adjust as necessary, but that's about the gist of it.
*/

int main() { //Add program arguments to choose between server and client.
    sk_server server;
    sk_create_server(&server);
    sk_remove_server(&server);
    
    /*sk_client client;
    sk_create_client(&client, "127.0.0.1"); 
    sk_remove_client(&client);*/
   
    return 0;
};
