#include <stdio.h>
#include "Types.h"
#include "LinkedList.h"

int main(int argc, char const *argv[])
{

    struct LinkedList* linked_list = create_linked_list();
    linked_list_append(linked_list,10);
    linked_list_append(linked_list,11);
    linked_list_append(linked_list,12);
    linked_list_insert(linked_list,1,1);
    linked_list_insert(linked_list,10,0);
    linked_list_remove(linked_list, 1);
    linked_list_pop(linked_list);
    linked_list_popleft(linked_list);
    size_t tamanho = get_lenth_linked_list(linked_list);

    printf("%d\n", tamanho);
    return 0;
}


