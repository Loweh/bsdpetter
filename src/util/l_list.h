#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ll stands for linked list

typedef struct ll_node ll_node;

struct ll_node {
	char value[10];
	struct ll_node *next;
};

void ll_create_head(ll_node **head, char value[10]);

int ll_get_node(ll_node *head, int pos);

void ll_push_node(ll_node *head, char value[10]);
void ll_remove_node(ll_node **head, int pos);
