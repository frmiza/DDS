#include "Queue.h"

struct Queue_int* queue_create();
void enqueue_int(struct Queue_int* queue, int data);
int dequeue_int(struct Queue_int* queue, int data);

struct Queue_int* queue_create()
{
    struct Queue_int queue;
    
}