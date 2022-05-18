/*******************************************************************************************************************************************************************
*Title			: Insertion
*Description		: This function performs inserting the new data into the given Red Black tree.
*Prototype		: int insert(tree_t **root, data_t item);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
            : item – New data to be inserted into the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"


int RBTree::insert(data_t item)
{
    try {
        tree_t* pt = new tree_t(item);

        // Do a normal BST insert
        root = bst_insert(root, pt);
        cout << "Before balancing Red-Black tree:\n";
        print_tree(root);
        cout << endl;

        // fix Red Black Tree violations
        fix_violation(root, pt);
        cout << "After balancing Red-Black tree:\n";
        print_tree(root);

        return SUCCESS;
    }
    catch (...) {
        return FAILURE;
    }
}


/* A utility function to insert
    a new node with given key
   in BST */
tree_t* RBTree::bst_insert(tree_t* root, tree_t* pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return pt;

    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left = bst_insert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = bst_insert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}


void RBTree::rotate_left(tree_t*& root, tree_t*& pt)
{
    tree_t* pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotate_right(tree_t*& root, tree_t*& pt)
{
    tree_t* pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
void RBTree::fix_violation(tree_t*& root, tree_t*& pt)
{
    tree_t* parent_pt = NULL;
    tree_t* grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) &&
        (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /* Case : A
           Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {

            tree_t* uncle_pt = grand_parent_pt->right;

            /* Case : 1
               The uncle of pt is also red, Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color ==
                RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotate_left(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotate_right(root, grand_parent_pt);
                swap(parent_pt->color,
                    grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        /* Case : B
           Parent of pt is right child
           of Grand-parent of pt */
        else
        {
            tree_t* uncle_pt = grand_parent_pt->left;

            /*  Case : 1
                The uncle of pt is also red Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color ==
                RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotate_right(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotate_left(root, grand_parent_pt);
                swap (parent_pt->color,
                    grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}
