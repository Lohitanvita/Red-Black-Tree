#include "rbt.h"

tree_t* search(tree_t* node, data_t key)
{
    // Base Cases: root is null or key is present at root
    if (node == NULL || node->data == key)
        return node;

    // Key is greater than root's key
    if (node->data < key)
        return search(node->right, key);

    // Key is smaller than root's key
    return search(node->left, key);
}
