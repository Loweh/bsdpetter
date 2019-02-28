#include "l_list.h"

//Add more functions if necessary, like maybe removing the entire list

void ll_create_head(ll_node **head, char value[10]) {
    ll_node *node = malloc(sizeof(ll_node));
	memcpy(node->value, value, 10);
	node->next = NULL;
	
	*head = node;
};

int ll_get_node(ll_node *head, int pos) {
    ll_node *node = head;
    
	for(int i = 0; i < pos; i++) {
	    if (node->next != NULL) {
	        node = node->next;  
	    } else {
	        return NULL;  
	    };
	};
	
	return node;
};

void ll_push_node(ll_node *head, char value[10]) {
    ll_node *node = head;
    
	while (node->next != NULL) {
		node = node->next;
	};
	
	node->next = malloc(sizeof(ll_node));
	memcpy(node->next->value, value, 10);
	node->next->next = NULL;
};

void ll_remove_node(ll_node **head, int pos) { //ll_pop_node is technically included in this, as well as ll_remove_head.
    if (pos != 0) {
        ll_node *node = ll_get_node(*head, pos - 1);
        
        if (node != NULL) {
            ll_node *temp = node->next;
            node->next = temp->next;
            free(temp);
        };
    } else {
        ll_node *temp = (*head)->next;
        free(*head);
        *head = temp;
    };
};