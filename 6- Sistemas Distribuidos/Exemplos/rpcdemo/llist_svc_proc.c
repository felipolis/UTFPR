/*
  llist printer RPC server implementation
  by Jeff Bezanson
*/

#include <stdlib.h>
#include "llist.h"

int result;

/* print out a list, returning the number of items printed */
int *print_list_1_svc(list *lst, struct svc_req *req)
{
    list *ptr;

    ptr = lst;
    result = 0;
    while (ptr != NULL) {
        printf("{%s, ", ptr->data);
        printf("%d, ", ptr->key);
        switch (ptr->col) {
        case ORANGE: printf("orange"); break;
        case PUCE: printf("puce"); break;
        case TURQUOISE: printf("turquoise");
        }
        printf("}\n");
        result++;
        ptr = ptr->next;
    }
    return &result;
}

int *sum_list_1_svc(list *lst, struct svc_req *req)
{
    list *ptr;

    ptr = lst;
    result = 0;
    while (ptr != NULL) {
        result += ptr->key;
        ptr = ptr->next;
    }
    return &result;
}
