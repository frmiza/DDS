#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdlib.h>
#include <stdio.h>
#include "Types.h"

typedef struct DataStructure DataStructure;

struct DataStructure
{
    struct Node_int *head;
    struct Node_int *tail;
    size_t length;

};

struct DataStructure* create_data_structure();
void insert_data_struct(struct DataStructure* data_structure, size_t index, int data);
void remove_data_struct(struct DataStructure* data_structure, size_t index);
int retrieve_data_struct(struct DataStructure* data_structure, size_t index);
size_t get_length_data_structure(struct DataStructure* data_structure);
struct DataStructure* delete_data_structure(struct DataStructure* data_structure);

#endif //DATA_STRUCTURE_H