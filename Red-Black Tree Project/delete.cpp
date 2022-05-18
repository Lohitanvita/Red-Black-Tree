/*******************************************************************************************************************************************************************
*Title			: Deletion
*Description		: This function performs deleting of the given data from the given Red Black tree.
*Prototype		: int delete(tree_t **root, data_t item);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – Data to be deleted from the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int RBTree::delete_node(data_t item)
{
    try {
        cout << "Before deleting the node, Red-Black tree:\n";
        print_tree(root);
        delete_node_helper(root, item);
        cout << "After deleting the node, Red-Black tree:\n";
        print_tree(root);
        return SUCCESS;
    }
    catch (...) {
        return FAILURE;
    }
    
}

// For balancing the tree after deletion
void RBTree::delete_fix(tree_t* x) {
    tree_t* s;
    while (x != root && x->color == RED) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == BLACK) {
                s->color = RED;
                x->parent->color = BLACK;
                rotate_left(root, x->parent);
                s = x->parent->right;
            }

            if (s->left->color == RED && s->right->color == RED) {
                s->color = BLACK;
                x = x->parent;
            }
            else {
                if (s->right->color == RED) {
                    s->left->color = RED;
                    s->color = BLACK;
                    rotate_right(root, s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = RED;
                s->right->color = RED;
                rotate_left(root, x->parent);
                x = root;
            }
        }
        else {
            s = x->parent->left;
            if (s->color == BLACK) {
                s->color = RED;
                x->parent->color = BLACK;
                rotate_right(root, x->parent);
                s = x->parent->left;
            }

            if (s->right->color == RED && s->right->color == RED) {
                s->color = BLACK;
                x = x->parent;
            }
            else {
                if (s->left->color == RED) {
                    s->right->color = RED;
                    s->color = BLACK;
                    rotate_left(root, s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = RED;
                s->left->color = RED;
                rotate_right(root, x->parent);
                x = root;
            }
        }
    }
    x->color = RED;
}

void RBTree::rb_transplant(tree_t* u, tree_t* v) {
    if (u->parent == NULL) {
        root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RBTree::delete_node_helper(tree_t* node, int key) {
    tree_t* z = NULL;
    tree_t* x;
    tree_t* y;
    while (node != NULL) {
        if (node->data == key) {
            z = node;
        }

        if (node->data <= key) {
            node = node->right;
        }
        else {
            node = node->left;
        }
    }

    if (z == NULL) {
        cout << "Key not found in the tree" << endl;
        return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == NULL) {
        x = z->right;
        rb_transplant(z, z->right);
    }
    else if (z->right == NULL) {
        x = z->left;
        rb_transplant(z, z->left);
    }
    else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        }
        else {
            rb_transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rb_transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
        delete_fix(x);
    }
}

tree_t* minimum(tree_t*& node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

tree_t* maximum(tree_t*& node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}
