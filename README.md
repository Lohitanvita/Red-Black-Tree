# Red-Black-Tree

A red–black tree is a kind of self-balancing binary search tree. The goal of this project is to implement various RBT operations.
Introduction
A red–black tree is a kind of self-balancing binary search tree. Each node of the binary tree has an extra bit, and that bit is often interpreted as the color (red or black) of the node. These color bits are used to ensure the tree remains approximately balanced during insertions and deletions.

Balance is preserved by painting each node of the tree with one of two colors (typically called ‘red’ or ‘black’) in a way that satisfies certain properties, which collectively constrain how unbalanced the tree can become in the worst case. When the tree is modified, the new tree is subsequently rearranged and repainted to restore the coloring properties. The properties are designed in such a way that this rearranging and recoloring can be performed efficiently.
The re-balancing is not perfect, but guarantees searching in O(log n) time, where n is the number of nodes of the tree. The insertion and deletion operations, along with the tree rearrangement and recoloring, are also performed in O(log n). Tracking the color of each node requires only 1 bit of information per node because there are only two colors. The tree does not contain any other data specific to its being a red–black tree, so its memory footprint is almost identical to a classic (uncolored) binary search tree. In many cases, the additional bit of information can be stored at no additional memory cost.
Requirement Details
Here are the requirements for the RBT project. In addition to the requirements imposed on a binary search tree the following must be satisfied by a red–black tree:

Each node is either red or black.
The root is black. This rule is sometimes omitted. Since the root can always be changed from red to black, but not necessarily vice versa, this rule has little effect on analysis.
All leaves (NIL) are black.
If a node is red, then both its children are black.
Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes. Some definitions: the number of black nodes from the root to a node is the node’s black depth; the uniform number of black nodes in all paths from root to the leaves is called the black-height of the red–black tree.

With this basic requirement, following operations to be implemented in RBT using tree ADT. 

1. Insertion
2. Deletion
3. Search
4. Find Min
5. Delete Min
6. Find Max
7. Delete Max
