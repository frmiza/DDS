#include "LinkedList.h"

struct Node_int* node_create(int data);
void delete_node_int(struct Node_int* node_to_delete);

struct Node_int* iterate(struct LinkedList_int* linked_list, size_t index);
void insert_int(struct LinkedList_int* linked_list, size_t index, int data);
void append_int(struct LinkedList_int* linked_list, int data);
void appendleft_int(struct LinkedList_int* linked_list, int data);
void remove_int(struct LinkedList_int* linked_list, size_t index);
void pop_int(struct LinkedList_int* linked_list);
void popleft_int(struct LinkedList_int* linked_list);
int retrieve_int(struct LinkedList_int* linked_list, size_t index);


struct LinkedList_int* linked_list_create()
{
    struct LinkedList_int* new_list = (struct LinkedList_int*)malloc(sizeof(struct LinkedList_int));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->lenght = 0;

    new_list->insert = insert_int;
    new_list->append = append_int;
    new_list->appendleft = appendleft_int;
    new_list->remove = remove_int;
    new_list->pop = pop_int;
    new_list->popleft = popleft_int;
    new_list->retrieve = retrieve_int;

    return new_list;
}

struct Node_int* node_create(int data)
{
    struct Node_int new_node_inst;
    new_node_inst.data = data;
    new_node_inst.next = NULL;
    
    struct Node_int* new_node_addr = (struct Node_int*)malloc(sizeof(struct Node_int));
    *new_node_addr = new_node_inst;
    return new_node_addr;
}

void delete_node_int(struct Node_int* node_to_delete)
{
    free(node_to_delete);
}

struct Node_int* iterate(struct LinkedList_int* linked_list, size_t index)
{   
    if (index < 0 || index >= linked_list->lenght)
    {
        printf("Index out of bound..\n");
        exit(9);
    }

    struct Node_int* cursor = linked_list->head;

    for(int iterator = 0; iterator < index; iterator++)
        cursor = cursor->next;
    
    return cursor;
}

void insert_int(struct LinkedList_int* linked_list, size_t index, int data)
{   
    if(linked_list->head == NULL){
        printf("empty list, imposible remove itens\n");
        return;
    }

    if(index == 0){
        appendleft_int(linked_list, data);
        return;
    }

    if(index == linked_list->lenght){
        append_int(linked_list, data);
        return;
    }

    if(linked_list->head == NULL && index > 0){
        printf("empty list, imposible inserte at: %d\n",index); 
        return;
    }
    
    struct Node_int* node_to_insert = node_create(data);
    struct Node_int* cursor = iterate(linked_list, index -1);
    cursor->next = node_to_insert;
    linked_list->lenght += 1;

}

void append_int(struct LinkedList_int* linked_list, int data)
{   
    struct Node_int* node_to_insert = node_create(data);
    if(linked_list->head == NULL)
        linked_list->head = node_to_insert;
    else
        linked_list->tail->next = node_to_insert;
    linked_list->tail = node_to_insert; 
    linked_list->lenght += 1;
}

void appendleft_int(struct LinkedList_int* linked_list, int data)
{   
    struct Node_int* node_to_insert = node_create(data);
    node_to_insert->next = linked_list->head;
    if(linked_list->head == NULL)
        linked_list->tail = node_to_insert;
    linked_list->head = node_to_insert;
    linked_list->lenght += 1;
}

void remove_int(struct LinkedList_int* linked_list, size_t index)
{

    if(linked_list->head == NULL){
        printf("empty list, imposible remove itens\n");
        return;
    }

    if(index == 0){
        popleft_int(linked_list);
        return;
    }

    struct Node_int* cursor = iterate(linked_list,index -1);
    struct Node_int* node_to_delete = cursor->next;
    cursor->next = node_to_delete->next;
    linked_list->tail = cursor;
    delete_node_int(node_to_delete);
    linked_list->lenght -= 1;
}

void pop_int(struct LinkedList_int* linked_list)
{   
    if(linked_list->head == NULL){
        printf("empty list, imposible remove itens\n");
        return;  
    }

    if(linked_list->lenght == 1){
        struct Node_int* node_to_delete = linked_list->head;
        delete_node_int(node_to_delete);
        linked_list->tail = NULL;
        linked_list->lenght -= 1;
        return;
    }

    struct Node_int* cursor = iterate(linked_list, linked_list->lenght - 2);
    struct Node_int* node_to_delete = cursor->next;
    linked_list->tail = cursor;
    delete_node_int(node_to_delete);
    linked_list->lenght -= 1;
}

void popleft_int(struct LinkedList_int* linked_list)
{   
    if(linked_list->head == NULL){
        printf("empty list, imposible remove itens\n");
        return;
    }
    struct Node_int* node_to_delete = linked_list->head;
    linked_list->head = node_to_delete->next;
    if(node_to_delete->next == NULL)
        linked_list->tail = NULL;
    delete_node_int(node_to_delete);
    linked_list->lenght -= 1;
    
}

int retrieve_int(struct LinkedList_int* linked_list, size_t index)
{
    if(index < 0 || index > linked_list->lenght)
    {
        printf("Index out of bound..\n");
        exit(9);
    }

    struct Node_int* cursor = iterate(linked_list, index);
    return cursor->data;
}