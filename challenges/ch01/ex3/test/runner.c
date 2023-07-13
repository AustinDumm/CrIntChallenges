#include <stdio.h>
#include <string.h>

#include "../include/bad_dl_list.h"

int main() {
    struct baddl_LinkedList *list = baddl_new_linked_list("0");

    struct baddl_Node *head = baddl_head(list);
    if (head == 0) {
        return -1;
    }

    baddl_insert_before(head, "-1");
    baddl_insert_after(head, "100");

    struct baddl_Node *tail = baddl_tail(list);

    baddl_insert_before(tail, "50");
    baddl_insert_after(tail, "1000");

    struct baddl_Node *before_old_tail = baddl_prev(tail);
    baddl_insert_after(before_old_tail, "74");
    baddl_insert_before(before_old_tail, "75");

    struct baddl_Node *fourth = baddl_elt(list, 3);
    baddl_delete_node(fourth);

    struct baddl_Node *seventy_four = baddl_node_of_elt(list, "74");
    baddl_remove(seventy_four);
    printf("%s\n", baddl_value(seventy_four));
    baddl_delete_node(seventy_four);

    struct baddl_Node *current = baddl_head(list);
    while (current) {
        char* value = baddl_value(current);
        printf("%s\n", value);
        current = baddl_next(current);
    }

    baddl_delete_linked_list(list);

    return 0;
}
