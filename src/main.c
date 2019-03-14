#include "util/l_list.h"
#include "sock/socket.h"

/*
Compiling this thing is already a pain so just remember this:

gcc main.c util/l_list.c sock/socket.c -o ../output/test -std=c99 -w

Adjust as necessary, but that's about the gist of it.
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Too many or too few arguments.\n", argc);
        return -1;
    };
    
    if (!strcmp(argv[1], "-s")) {
        printf("Starting server...\n");
        
        sk_server server;
        sk_create_server(&server);
        sk_remove_server(&server);
    } else if (!strcmp(argv[1], "-c")) {
        printf("Starting client...\n");
        
        sk_client client;
        sk_create_client(&client, "127.0.0.1"); 
        sk_remove_client(&client);
    } else {
        printf("Invalid argument.\n");
    };
    
    /* This bit of linked list test code is going to stay because I keep forgetting how it works :meow:.
    ll_node *head = NULL;
    int test = 1, test2 = 2, test3 = 3, test4 = 4;
    
    ll_create_head(&head, &test);
    ll_push_node(head, &test2);
    ll_push_node(head, &test3);
    
    ll_set_value(&head, 2, &test4);
    
    ll_node *node = NULL;
    node = ll_get_node(head, 2);
    int *value = node->value;
    
    printf("%i\n", *value);
    
    ll_remove_list(&head);
    */
   
    return 0;
};
