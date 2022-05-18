#pragma once
/***************************************************************************************************************************************************************
*Title		: This the header file for the Red Black Tree
****************************************************************************************************************************************************************/
#ifndef RBT_H
#define RBT_H
#define SUCCESS 0
#define FAILURE -1
#include <iostream>
#include <algorithm>

using namespace std;

typedef int data_t;

enum Color {RED=0, BLACK=1};

typedef struct node
{
	struct node* left;
	struct node* right;	
    struct node* parent;
    data_t data;
    int color;

    // Constructor
    node(int data)
    {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
}tree_t;

class RBTree {
protected:
    tree_t* bst_insert(tree_t*, tree_t*);
    void rotate_left(tree_t*&, tree_t*&);
    void rotate_right(tree_t*&, tree_t*&);
    void fix_violation(tree_t*&, tree_t*&);
    void delete_fix(tree_t*);
    void rb_transplant(tree_t*, tree_t*);
    void delete_node_helper(tree_t*, int);
public:
    tree_t* root;
    RBTree() { root = NULL; }
    int insert(data_t);
    int delete_node(data_t);
    int delete_minimum(tree_t*);
    int delete_maximum(tree_t*);
};

tree_t* search(tree_t*, data_t);
int find_minimum(tree_t*, data_t*);
int find_maximum(tree_t*, data_t*);
extern void print_tree(tree_t*);
extern void print_node(tree_t*);


#endif
