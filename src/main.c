#include "util/l_list.h"

/*
Compiling this thing is already a pain so just remember this:

gcc main.c util/l_list.c -o test -std=c99 -w

Adjust as necessary, but that's about the gist of it.
*/

int main() {
    ll_node *head = NULL;
    ll_create_head(&head, "meow");
    ll_push_node(head, "meow2");
    ll_push_node(head, "meow3");

    ll_node *node1, *node2;
    node1 = ll_get_node(head, 1);
    node2 = ll_get_node(head, 2);
	
    if (node1 == -1) {
        return 2;
    } else if (node2 == -1) {
        return 3;  
    };
	
    printf("%s\n%s\n%s\n", head->value, node1->value, node2->value);
	
    ll_remove_node(&head, 1);
	
    printf("%s\n%s\n", head->value, head->next->value);
    return 0;
};
