#include <stdlib.h>

typedef struct node
{
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) 
{
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

// PAS ENCORE RELU

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) 
{
    node_t *check = *head;
    while (check)
    {
        if (cmp(check->val, val) == 0) return 0;
        check = check->next;
    }

    node_t *previous = NULL;
    node_t *new_node = malloc(sizeof(node_t));
    
    if (!new_node) return -1;

    new_node->next = NULL;
    new_node->val = val;
    if (*head == NULL) *head = new_node;
    node_t *current = *head;
    for (int i=0; current != NULL; i++)
    {
        int res = cmp(current->val, val);
        if (res > 0)
        {
            if (previous == NULL)
            {
                *head = new_node;
                new_node->next = current;
                return 0;
            }
            previous->next = new_node;
            new_node->next = current;
            return 0;
        }
        if (!res) return 0;
        previous = current;
        current = current->next;
    }
    previous->next = new_node;
    return 0;
}