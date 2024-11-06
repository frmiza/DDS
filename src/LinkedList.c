#include "DataStructure.h"
#include "LinkedList.h"

struct LinkedList
{
    struct DataStructure* data_structure;
};

LinkedList* create_linked_list()
{
    struct LinkedList* new_linked_list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    struct DataStructure* data_struct = data_structure_create();
    new_linked_list->data_structure = data_struct;
    return new_linked_list;
}

void insert_linked_list(struct LinkedList* linked_list, int data, size_t index)
{
    insert_data_struct(linked_list->data_structure,index,data);
}

void append_linked_list(struct LinkedList* linked_list, int data)
{
    size_t last_index = get_length_data_structure(linked_list->data_structure);
    insert_data_struct(linked_list->data_structure, last_index, data);
}

void appendleft_linked_list(struct LinkedList* linked_list, int data)
{
    insert_data_struct(linked_list->data_structure, 0,data);
}

void remove_linked_list(struct LinkedList* linked_list, size_t index)
{
    remove_data_struct(linked_list->data_structure, index);
}

void pop_linked_list(struct LinkedList* linked_list)
{
    size_t last_index = get_length_data_structure(linked_list->data_structure);
    remove_data_struct(linked_list->data_structure, last_index);
}

void popleft_linked_list(struct LinkedList* linked_list)
{
    remove_data_struct(linked_list->data_structure, 0);
}

size_t get_lenth_linked_list(struct LinkedList* linked_list)
{
    return get_length_data_structure(linked_list->data_structure);
}