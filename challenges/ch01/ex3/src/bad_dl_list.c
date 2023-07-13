#include <stdlib.h>
#include <string.h>

#include "../include/bad_dl_list.h"

struct baddl_Node {
    char *value;

    struct baddl_Node *next;
    struct baddl_Node *prev;

    struct baddl_LinkedList *owner;
};

struct baddl_LinkedList {
    struct baddl_Node *head;
    struct baddl_Node *tail;
};

struct baddl_LinkedList *baddl_new_linked_list(char* value) {
    struct baddl_LinkedList *list = calloc(1, sizeof(struct baddl_LinkedList));

    if (!list) {
        return NULL;
    }

    struct baddl_Node *node = calloc(1, sizeof(struct baddl_Node));

    if (!node) {
        return NULL;
    }

    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    node->owner = list;

    list->head = node;
    list->tail = node;

    return list;
}

void baddl_delete_linked_list(struct baddl_LinkedList*list) {
    struct baddl_Node *current = list->head;
    while (current) {
        struct baddl_Node *next = current->next;
        baddl_delete_node(current);
        current = next;
    }

    free(list);
}

void baddl_delete_node(struct baddl_Node *node) {
    struct baddl_LinkedList* owner = node->owner;
    if (!owner) {
        free(node);
        return;
    }

    baddl_remove(node);

    free(node);
}


int baddl_count(struct baddl_LinkedList* list) {
    int count = 0;
    struct baddl_Node *current = list->head;

    while (current) {
        ++count;
        current = current->next;
    }

    return count;
}

struct baddl_Node *baddl_head(struct baddl_LinkedList *list) {
    return list->head;
}

struct baddl_Node *baddl_tail(struct baddl_LinkedList *list) {
    return list->tail;
}

struct baddl_Node *baddl_elt(struct baddl_LinkedList *list, int count) {
    struct baddl_Node *current = list->head;

    while (count > 0) {
        --count;
        current = current->next;
        if (current == NULL) {
            return NULL;
        }
    }

    return current;
}


int baddl_index_of_node(struct baddl_Node *node) {
    int count = 0;

    while (node != NULL) {
        ++count;
        node = node->prev;
    }

    return count;
}

int baddl_index_of_elt(struct baddl_LinkedList* list, char* value) {
    int count = 0;
    struct baddl_Node *current = list->head;

    while (strcmp(value, current->value) != 0) {
        ++count;
        current = current->next;

        if (current == NULL) {
            return -1;
        }
    }

    return count;
}

struct baddl_Node *baddl_node_of_elt(struct baddl_LinkedList* list, char* value) {
    struct baddl_Node *current = list->head;

    while (strcmp(value, current->value) != 0) {
        current = current->next;

        if (current == NULL) {
            return NULL;
        }
    }

    return current;
}

void baddl_insert_after(struct baddl_Node *node, char *value) {
    struct baddl_Node* new_node = calloc(1, sizeof(struct baddl_Node));

    new_node->value = value;
    new_node->next = node->next;
    new_node->prev = node;
    new_node->owner = node->owner;

    if (node->next == NULL) {
        node->owner->tail = new_node;
    } else {
        node->next->prev = new_node;
    }
    node->next = new_node;
}

void baddl_insert_before(struct baddl_Node *node, char *value) {
    struct baddl_Node* new_node = calloc(1, sizeof(struct baddl_Node));

    new_node->value = value;
    new_node->next = node;
    new_node->prev = node->prev;
    new_node->owner = node->owner;

    if (node->prev == NULL) {
        node->owner->head = new_node;
    } else {
        node->prev->next = new_node;
    }
    node->prev = new_node;
}

void baddl_remove(struct baddl_Node* node) {
    struct baddl_LinkedList* owner = node->owner;
    if (owner == NULL) {
        // Already removed, no owner
        return;
    }

    struct baddl_Node *prev = node->prev;
    if (prev) {
        prev->next = node->next;
    } else {
        node->owner->head = node->next;
    }

    struct baddl_Node *next = node->next;
    if (next) {
        next->prev = node->prev;
    } else {
        node->owner->tail = node->prev;
    }
}

struct baddl_Node *baddl_next(struct baddl_Node *node) {
    return node->next;
}

struct baddl_Node *baddl_prev(struct baddl_Node *node) {
    return node->prev;
}

struct baddl_Node *baddl_index(struct baddl_Node* node, int index) {
    if (index > 0) {
        while (index > 0) {
            --index;
            node = node->next;
            if (node == NULL) {
                return NULL;
            }
        }
        return node;
    } else {
        while (index < 0) {
            ++index;
            node = node->prev;
            if (node == NULL) {
                return NULL;
            }
        }
        return node;
    }
}

char* baddl_value(struct baddl_Node* node) {
    return node->value;
}
