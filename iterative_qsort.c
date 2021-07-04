#define MAX_LEVELS 1000

void iterative_quicksort(node_t **list, int elements){
    if (!*list || !(*list)->next)
        return;

    int beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R;
    beg[0] = 0;
    end[0] = elements;
    while (i>=0) {
        L = beg[i];
        R = end[i] - 1;
        if (i == MAX_LEVELS-1){
            printf("i exceed MAX_LEVELS\n");
            return;
        }
        if (L<R) {
            node_t *pivot= *list;
            for (int i=0;i<L; i++){
                pivot = pivot->next;
            }
            node_t *lnode = pivot;
            node_t *rnode = *list;
            int pvalue = pivot->value;
            for (int i=0; i<R; i++){
                rnode = rnode->next;
            }
            while (L<R) {
                while ((rnode->value >= pvalue ) && L<R){
                    rnode = rnode->prev;
                    R--;
                }
                if (L<R){
                    lnode->value = rnode->value;
                    L++;
                    lnode = lnode->next;
                }
                while ((lnode->value <= pvalue) && L<R){ //change pvalie to pivot->value would be wrong
                    lnode = lnode->next;
                    L++;
                }
                if (L<R){
                    rnode->value = lnode->value;
                    R--;
                    rnode = rnode->prev;
                }
            }
            lnode->value = pvalue;
            beg[i+1] = L+1;
            end[i+1] = end[i];
            end [i] = L;
            i++;
        }else{
            i--;
        }
    }    
}