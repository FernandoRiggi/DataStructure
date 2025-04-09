#ifndef LIST_H
#define LIST_H

typedef struct t_list{;
    int max;
    int size;
    int *itens;
} t_list;

t_list* create_list();
int is_full(t_list* list);
int is_empty(t_list* list);
int double_size(t_list* list);
t_list* append(int elem, t_list* list);
t_list* insert(int elem, int index, t_list* list);
t_list* update(int elem, int index, t_list* list);
t_list* remove_by_index(int index, t_list* list);
int remove_by_element(int elem, t_list* list);
int index_of(int elem, t_list* list);
int get(int index, t_list* list);
int count(int elem, t_list* list);
int size(t_list* list);
t_list* clear(t_list* list);
int is_sorted(t_list* list);
t_list* copy_list(t_list* list);
t_list* copy_unique(t_list* list);
t_list* inverted_new_list(t_list* list);
t_list* invert_list(t_list* list);
t_list* merge(t_list* L1, t_list* L2);
int remove_all_occurences(int elem, t_list* list);
#endif