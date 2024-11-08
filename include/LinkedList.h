#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Types.h"
#include "DataStructure.h"

typedef struct LinkedList LinkedList;

struct LinkedList* create_linked_list();
void delete_linked_list(struct LinkedList* linked_list);

void insert_linked_list(struct LinkedList* linked_list, int data, size_t index);
void append_linked_list(struct LinkedList* linked_list, int data);
void appendleft_linked_list(struct LinkedList* linked_list, int data);
void remove_linked_list(struct LinkedList* linked_list, size_t index);
void pop_linked_list(struct LinkedList* linked_list);
void popleft_linked_list(struct LinkedList* linked_list);
int retrieve_linked_list(struct LinkedList* linked_list, size_t index);
size_t get_lenth_linked_list(struct LinkedList* linked_list);

#endif //LINKED_LIST_H