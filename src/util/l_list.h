#ifndef L_LIST_H
#define L_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ll is for linked list.
//All functions with a pos argument start at zero, like arrays do.

typedef struct {
    void *value;
    struct ll_node *next;
} ll_node;

void ll_create_head(ll_node **head, void *value);

int ll_get_node(ll_node *head, int pos);

void ll_set_value(ll_node **head, int pos, void *value);

void ll_push_node(ll_node *head, void *value);

void ll_remove_node(ll_node **head, int pos);
void ll_remove_list(ll_node **head);

#endif
