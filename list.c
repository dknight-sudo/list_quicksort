typedef struct __node {                   
    int value;
    struct __node *next;
    struct __node *prev;
} node_t;

node_t *list_make_node_t(node_t *list, int val){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = val;
    node->next = list;
    return node;
}

static inline void list_add_node_t(node_t **list, node_t *node_t) {
    node_t->next = *list;
    *list = node_t;
}

 void list_concat(node_t **left, node_t *right) {
    while (*left){
        left = &((*left)->next);
    }
    *left = right;
}

static bool list_is_ordered(node_t *list) {
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = false;
        } else {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

static void list_display(node_t *list) {
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}
static void list_free(node_t *list) {
    node_t *temp = list;
    while (list){
        temp = list;
        list = list->next;
        free(temp);
    }
}
