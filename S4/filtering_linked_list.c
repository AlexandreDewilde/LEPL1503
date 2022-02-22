#include <stdlib.h>
#include <string.h>


struct node {
    struct node *next;
    int hash;
    int id;
    char name[20];
    char buffer[100];
    unsigned int timestamp;
    char acl;
    short flow;
    char *parent;
    void *fifo;
};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head) 
{
    if (head == NULL) return NULL;
    struct node* new_node = malloc(sizeof(*head));

    if (new_node == NULL) return NULL;
    if (head->next == NULL)
    {
        memcpy(new_node, head, sizeof(*head));
        new_node->next = NULL;
        return new_node;
    }
    memcpy(new_node, head, sizeof(*head));
    new_node->next = pair_filter(head->next->next);
    return new_node;
}