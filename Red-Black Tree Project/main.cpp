/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "rbt.h"

int main()
{
	/* Declare the pointers */
	RBTree tree;
	data_t data;
	data_t minimum;
	data_t maximum;
	char option;
	tree_t* result;

	do
	{
		/* Display the menu */
		cout << "1. Insert\n2. Delete\n3. Search\n4. Find Minimum\n5. Delete Minimum\n6. Find Maximum\n7. Delete Maximum\n";

		cout << "Enter the choice:";
		int operation;
		cin >> operation;

		/* Jump to the option entered by the user */
		switch (operation)
		{
		case 1:
			cout <<"Enter the data to be inserted into the RB Tree: ";
			cin >> data;
			tree.insert(data);
			break;
		case 2:
			cout << "Enter the data to be deleted from the RB Tree: ";
			cin >> data;
			tree.delete_node(data);
			break;
		case 3:
			cout << "Enter the node to be searched in RBTree: ";
			cin >> data;
			result = search(tree.root, data);
			print_node(result);
			break;
		case 4:
			find_minimum(tree.root, &minimum);
			cout << "Minimum data:" << minimum << endl;
			break;
		case 5:
			tree.delete_minimum(tree.root);			
			break;
		case 6:
			find_maximum(tree.root, &maximum);
			cout << "Maximum data:" << maximum << endl;
			break;
		case 7:
			tree.delete_maximum(tree.root);			
			break;
		}

		cout << "\nWant to continue? Press [yY | nN]: ";
		cin >> option;
	} while (option == 'y' || option == 'Y');

	return 0;
}
