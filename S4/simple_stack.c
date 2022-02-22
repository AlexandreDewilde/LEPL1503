#include <stdlib.h>


struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result)
{
    if (head == NULL || *head == NULL) return 1;
    // if (!head || !(*head)) return 1;

    struct node *deleted = (*head);
    strcpy(result, (*head)->name);
    *head = (*head)->next;

    free(deleted->name);
    free(deleted);
    return 0;
}


/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value)
{
    if (head == NULL || *head == NULL) return 1;
    // if (!head || !(*head)) return 1;

    struct node* elem = malloc(sizeof(struct node));
    if (elem == NULL) return 1;

    elem->next = *head;
    elem->name = malloc(strlen(value)+1);
    strcpy(elem->name, value);
    *head = elem;
    
    return 0;
}