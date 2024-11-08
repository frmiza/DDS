#ifndef NODE_H
#define NODE_H

struct Node_int
{
    int data;
    struct Node_int *next;
    struct Node_int *prev;
};

#endif //NODE_H