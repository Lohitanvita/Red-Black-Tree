/*******************************************************************************************************************************************************************
*Title			: Delete Minimum
*Description		: This function deletes the minimum data from the given Red Black tree.
*Prototype		: int delete_minimum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int RBTree::delete_minimum(tree_t* root)
{
	try {
		data_t minimum;
		find_minimum(root, &minimum);
		cout << "RBtree before deleting minimum node:\n";
		print_tree(root);
		delete_node(minimum);
		cout << "RBtree after deleting minimum node:\n";
		print_tree(root);
		return SUCCESS;
	}
	catch (...) {
		return FAILURE;
	}
}
