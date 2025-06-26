#include <stdio.h>
#include "Types.h"
#include "LinkedList.h"

int main(int argc, char const *argv[])
{

    struct LinkedList* linked_list = create_linked_list();
    append_linked_list(linked_list,0);
    append_linked_list(linked_list,1);
    append_linked_list(linked_list,2);
    insert_linked_list(linked_list,3,3);
    insert_linked_list(linked_list,4,0);
    remove_linked_list(linked_list, 5);
    //pop_linked_list(linked_list);
    //popleft_linked_list(linked_list);
    size_t tamanho = get_lenth_linked_list(linked_list);

    for (size_t i = 0; i < get_lenth_linked_list(linked_list) ; i++)
    {
        printf("%d ", retrieve_linked_list(linked_list, i));
    }
    
    printf("\n");
    printf("tamanho: %d\n", tamanho);
    return 0;
}


