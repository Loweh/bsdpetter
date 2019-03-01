#include "util/l_list.h"
#include "sock/socket.h"

/*
Compiling this thing is already a pain so just remember this:

gcc main.c util/l_list.c sock/socket.c -o ../output/test -std=c99 -w

Adjust as necessary, but that's about the gist of it.
*/

int main() { //Add program arguments to choose between server and client.
    ll_node *head = NULL;
    sk_client client1; //, client2, client3;
    
    sk_create_client(&client1, "127.0.0.1"); //Parts in comments are old linked list testing.
    /*sk_create_client(&client2, "127.0.0.1");
    sk_create_client(&client3, "127.0.0.1");
    ll_create_head(&head, &client1);
    
    ll_push_node(head, &client2);
    ll_push_node(head, &client3);
    
    ll_remove_node(&head, 1);
    
    ll_node *node1 = NULL, *node2 = NULL;
    node1 = ll_get_node(head, 0);
    node2 = ll_get_node(head, 1);
	
    if (node1 == NULL) {
        return 2;
    } else if (node2 == NULL) {
        return 3;  
    };
    
    sk_client *test1 = node1->value;
    sk_client *test2 = node2->value;
    
    printf("%i\n%i\n", test1->sock, test2->sock); */
    
    return 0;
};
