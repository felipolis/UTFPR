/*
  llist printer RPC client
  by Jeff Bezanson
*/

#include "llist.h"

list *mk_list(char *data, int key, color c)
{
    list *lst;

    lst = (list*)malloc(sizeof(list));
    if (lst == NULL)
        return NULL;
    lst->data = data;
    lst->key = key;
    lst->col = c;
    lst->next = NULL;
    return lst;
}

int main(int argc, char *argv[])
{
    list *l, *new;
    CLIENT *cl;
    int *result;

    if (argc < 2)
        return 1;

    l = new = mk_list("one", 1, ORANGE);
    new = mk_list("two", 2, TURQUOISE);
    new->next = l; l = new;
    new = mk_list("three", 3, ORANGE);
    new->next = l; l = new;

    cl = clnt_create(argv[1], PRINTER, PRINTER_V1, "tcp");
    if (cl == NULL) {
        printf("error: could not connect to server.\n");
        return 1;
    }
    result = print_list_1(l, cl);
    if (result == NULL) {
        printf("error: RPC failed!\n");
        return 1;
    }
    printf("client: server says it printed %d items.\n", *result);

    return 0;
}
