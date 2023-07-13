struct baddl_LinkedList;
struct baddl_Node;

struct baddl_LinkedList *baddl_new_linked_list(char*);
void baddl_delete_linked_list(struct baddl_LinkedList*);
void baddl_delete_node(struct baddl_Node*);

int baddl_count(struct baddl_LinkedList*);

struct baddl_Node *baddl_head(struct baddl_LinkedList*);
struct baddl_Node *baddl_tail(struct baddl_LinkedList*);
struct baddl_Node *baddl_elt(struct baddl_LinkedList*, int);

int baddl_index_of_node(struct baddl_Node*);
int baddl_index_of_elt(struct baddl_LinkedList*, char*);
struct baddl_Node *baddl_node_of_elt(struct baddl_LinkedList*, char*);

void baddl_insert_after(struct baddl_Node*, char*);
void baddl_insert_before(struct baddl_Node*, char*);

void baddl_remove(struct baddl_Node*);

struct baddl_Node *baddl_next(struct baddl_Node*);
struct baddl_Node *baddl_prev(struct baddl_Node*);
struct baddl_Node *baddl_index(struct baddl_Node*, int);

char* baddl_value(struct baddl_Node*);

