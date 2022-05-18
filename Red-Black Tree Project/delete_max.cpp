/*******************************************************************************************************************************************************************
*Title			: Delete Maximum
*Description		: This function deletes the maximum data from the given Red Black tree.
*Prototype		: int delete_maximum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int RBTree::delete_maximum(tree_t* root)
{
	try {
		data_t maximum;
		find_maximum(root, &maximum);
		cout << "RBtree before deleting maximum node:\n";
		print_tree(root);
		delete_node(maximum);
		cout << "RBtree after deleting maximum node:\n";
		print_tree(root);
		return SUCCESS;
	}
	catch (...) {
		return FAILURE;
	}
}