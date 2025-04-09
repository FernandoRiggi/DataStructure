#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    t_list* list1 = create_list();
    t_list* list2 = create_list();
    t_list* merged;
    t_list* clone_list = create_list();

    // Testando append
    append(list1, 5);
    append(list1, 3);
    append(list1, 8);
    append(list1, 1);

    append(list2, 4);
    append(list2, 6);
    append(list2, 2);

    printf("List 1: ");
    print_list(list1);

    printf("List 2: ");
    print_list(list2);

    // Testando sort
    sort(list1);
    sort(list2);
    printf("Sorted List 1: ");
    print_list(list1);

    printf("Sorted List 2: ");
    print_list(list2);

    // Testando merge
    merged = merge(list1, list2);
    printf("Merged List: ");
    print_list(merged);

    // Testando reverse
    reverse(merged);
    printf("Reversed Merged List: ");
    print_list(merged);

    // Testando clone
    clone(merged, clone_list);
    printf("Cloned List: ");
    print_list(clone_list);

    // Testando remoção
    remove_item(clone_list, 4);
    printf("Cloned List after removing 4: ");
    print_list(clone_list);

    // Testando pop_front e pop_back
    t_node* popped_front = pop_front(clone_list);
    if(popped_front) {
        printf("Popped front: %d\n", popped_front->item);
        free(popped_front);
    }

    t_node* popped_back = pop_back(clone_list);
    if(popped_back) {
        printf("Popped back: %d\n", popped_back->item);
        free(popped_back);
    }

    printf("Cloned List after popping: ");
    print_list(clone_list);

    // Liberando memória
    destroy_list(list1);
    destroy_list(list2);
    destroy_list(merged);
    destroy_list(clone_list);

    return 0;
}
