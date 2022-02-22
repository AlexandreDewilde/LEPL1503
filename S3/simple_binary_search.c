#include <stdlib.h>
/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;


typedef struct bt{
    struct node* root;
} bt_t;


/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value)
{
    if (tree == NULL) return 0;
    return contains_utils(tree->root, value);
}

int contains_utils(struct node* root, int value)
{
    if (root == NULL) return 0;
    return root->value == value || utils(root->left, value) || utils(root->right, value);
}

