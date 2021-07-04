#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "iterative_list.c"
#include "quick_sort.c"
#include "iterative_qsort.c"



int main(int argc, char **argv) {
    size_t count = 1000;

    node_t *list = NULL;
    while (count--)
        list = list_make_node_t(list, random() % 1024);

    list_display(list);
    iterative_quicksort(&list,1000);
    list_display(list);


    if (!list_is_ordered(list))
        printf("not inorder");
    list_free(list);
    return EXIT_SUCCESS;
}         