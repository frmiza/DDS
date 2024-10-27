#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "Types.h"

struct LinkedList_int
{
    struct Node_int *head;
    struct Node_int *tail;
    int lenght;

    void (*insert)(struct LinkedList_int* linked_list, size_t index, int data);
    void (*append)(struct LinkedList_int* linked_list, int data);
    void (*appendleft)(struct LinkedList_int* linked_list, int data);
    void (*remove)(struct LinkedList_int* linked_list, size_t index);
    void (*pop)(struct LinkedList_int* linked_list);
    void (*popleft)(struct LinkedList_int* linked_list);
    int (*retrieve)(struct LinkedList_int* linked_list, size_t index);

};

struct LinkedList_int* linked_list_create();

#endif //LINKEDLIST_Hj