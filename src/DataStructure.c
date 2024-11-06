#include "DataStructure.h"

struct Node_int* create_node(int data);
void delete_node(struct Node_int* node_to_delete);
struct Node_int* iterate(struct DataStructure* data_structure, size_t index);

struct DataStructure* create_data_structure()
{
    struct DataStructure* new_structure = (struct DataStructure*)malloc(sizeof(struct DataStructure));
    new_structure->head = NULL;
    new_structure->tail = NULL;
    new_structure->length = 0;

    return new_structure;
}

struct Node_int* create_node(int data)
{
    struct Node_int new_node_inst;
    new_node_inst.data = data;
    new_node_inst.next = NULL;
    new_node_inst.prev = NULL;
    
    struct Node_int* new_node_addr = (struct Node_int*)malloc(sizeof(struct Node_int));
    *new_node_addr = new_node_inst;
    return new_node_addr;
}

void delete_node(struct Node_int* node_to_delete)
{
    free(node_to_delete);
}

struct Node_int* iterate(struct DataStructure* data_structure, size_t index)
{   
    if (index < 0 || index >= data_structure->length)
    {
        printf("Index out of bound..\n");
        exit(9);
    }

    struct Node_int* cursor = data_structure->head;

    for(int iterator = 0; iterator < index; iterator++)
        cursor = cursor->next;
    
    return cursor;
}

void insert_data_struct(struct DataStructure* data_structure, size_t index, int data)
{   
    if(data_structure == NULL){
        printf("empty list, imposible inserte at: %d\n",index); 
        return;
    }

    struct Node_int* node_to_insert = node_create(data);

    if(index == 0){
        node_to_insert->next = data_structure->head;
        node_to_insert->prev = NULL;
        
        if(data_structure->length == 0)
            data_structure->tail = node_to_insert;
        data_structure->head = node_to_insert;
        data_structure->length += 1;
        return;
    }

    if(index == data_structure->length){
        node_to_insert->prev = data_structure->tail;
        data_structure->tail->next = node_to_insert;
        data_structure->tail = node_to_insert; 
        data_structure->length += 1;
        return;
    }

    struct Node_int* cursor_prev_pos = iterate(data_structure, index -1);
    struct Node_int* cursor_insert_pos = cursor_prev_pos->next;
    node_to_insert->next = cursor_insert_pos;
    cursor_insert_pos->prev = node_to_insert;
    node_to_insert->prev = cursor_prev_pos;
    cursor_prev_pos->next = node_to_insert;
    data_structure->length += 1;

}

void remove_data_struct(struct DataStructure* data_structure, size_t index)
{

    if(data_structure == NULL){
        printf("empty list, imposible remove itens\n");
        return;
    }

    if(index == 0){
        struct Node_int* node_to_delete = data_structure->head;
        data_structure->head = node_to_delete->next;
        if(data_structure->length == 1)
            data_structure->tail = NULL;
        delete_node_int(node_to_delete);
        data_structure->length -= 1;
        return;
    }

    if(index == data_structure->length){
        struct Node_int* node_to_delete = data_structure->tail;
        data_structure->tail =  node_to_delete->prev;
        data_structure->tail->next = NULL;
        delete_node_int(node_to_delete);
        data_structure->length -= 1;
        return;
    }

    struct Node_int* cursor = iterate(data_structure,index -1);
    struct Node_int* node_to_delete = cursor->next;
    cursor->next = node_to_delete->next;
    delete_node_int(node_to_delete);
    data_structure->length -= 1;
}

int retrieve_data_struct(struct DataStructure* data_structure, size_t index)
{
    if(index < 0 || index > data_structure->length)
    {
        printf("Index out of bound..\n");
        exit(9);
    }

    struct Node_int* cursor = iterate(data_structure, index);
    return cursor->data;
}

size_t get_length_data_structure(struct DataStructure* data_structure)
{
    return data_structure->length;
}