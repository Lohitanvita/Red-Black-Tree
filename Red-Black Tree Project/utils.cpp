#include "rbt.h";


//Helper function for inorder traversal of RBT
void print_tree(tree_t* node)
{
    if (node == nullptr)
        return;

    print_tree(node->left);
    print_node(node);
    print_tree(node->right);
}

void print_node(tree_t* node)
{
    cout << "(" << node->data << ")" << "--" << "(" << node->color << ")  ";
}