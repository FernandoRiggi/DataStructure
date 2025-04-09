#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _node{
    int item;
    struct _node *next;
} t_node;

typedef struct {
    int size;
    t_node* head;
    t_node* tail;
}t_linked_list;

t_linked_list* create_list();
int is_empty(t_linked_list*);
void clear(t_linked_list*);
void destroy(t_linked_list*);
void append(t_linked_list*, int);
int remove_item(t_linked_list*, int);
int remove_at(t_linked_list*, int);
void insert(t_linked_list*, int, int); 
void sort(t_linked_list*); 
void print_list(t_linked_list*);
#endif;