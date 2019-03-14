#include "l_list.h"

//Add more functions if necessary

void ll_create_head(ll_node **head, void *value) {
    ll_node *node = malloc(sizeof(ll_node));
    node->value = value;
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

void ll_set_value(ll_node **head, int pos, void *value) {
    if (pos != 0) {
        ll_node *node = ll_get_node(*head, pos);
        
        if (node != NULL) {
            node->value = value;
        };
    } else {
        (*head)->value = value;
    };
};

void ll_push_node(ll_node *head, void *value) {
    ll_node *node = head, *temp;
    
    while (node->next != NULL) {
        node = node->next;
    };
	
    temp = node->next; //Have to add a temp since void pointers somehow broke this.
    temp = malloc(sizeof(ll_node));
    temp->value = value;
    temp->next = NULL;
    node->next = temp;
};

void ll_remove_node(ll_node **head, int pos) { //ll_pop_node is technically included in this, as well as ll_remove_head.
    if (pos != 0) {
        ll_node *node = ll_get_node(*head, pos);
        
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

void ll_remove_list(ll_node **head) { //I'm pretty sure this works but it probably needs external testing for memory leaks to be sure.
    int finished = 0;
    ll_node *next = *head, *temp;
    
    while (!finished) {
        if (next == NULL) {
            finished++;
        } else {
            temp = next->next;
            free(next);
            next = temp;
        };
    };
};