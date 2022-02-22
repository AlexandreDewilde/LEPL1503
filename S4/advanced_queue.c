#include <stdlib.h>

typedef struct node
{
    struct node* next;
    int value;
} node_t;

typedef struct queue
{
    struct node* tail;
    int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val)
{
    node_t* node = malloc(sizeof(node_t));
    if (!node) return -1;
    node->value = val;
    q->size++;
    if (q->size == 1) {

        node->next = node;
        q->tail = node;
        return 0;
    }
    node->next = q->tail->next;
    q->tail->next = node;
    return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q)
{
    node_t *node = q->tail;
    node_t *next = node->next;
    int val = node->value;
    free(node);
    q->size--;
    if (q->size == 0)
    {     
        q->tail = NULL;
        return val;
    }
    node_t *current = next;
    // Very weird to loop to search for the new end, is there another way?
    while (q->size > 1 && node != current->next)
    {
        current = current->next;
    }
    current->next = next;
    q->tail = current;
    return val;
}