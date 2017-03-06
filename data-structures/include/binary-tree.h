#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
/**
 *  binary-search-tree.h
 *
 *  Author: David Piper
 *
 *      The purpose of this header file is to define the opertions
 *  and structure of a binary search tree.
 */
#include <stdlib.h>

struct _BSTNode
{
    int mValue; /* the stored datum */
    struct _BSTNode* mLeft;
    struct _BSTNode* mRight;
};

typedef struct _BSTNode BST_Node:

/**
 *  BST_initNode
 *
 *      Setup the binary tree node.
 */
BST_Node* BST_initNode(int value);

/**
 *  BST_insert
 *
 *      Inserts an element into the
 *  binary tree.
 */
void BST_insert(BST_Node* root, int value);

/**
 *  BST_delete
 *
 *      Deletes an element from the
 *  binary tree.
 */
void BST_delete(BST_Node* root, int value);

/**
 *  BST_contains
 *
 *      Search to see if the tree has the given
 *  value.
 */
int BST_contains(BST_Node* root, int value);

/**
 *  BST_traverseInorder
 *
 *      Performs an inorder traversal on the BST.
 */
void BST_traverseInorder(BST_Node* root);

/**
 *  BST_traversePreorder
 *
 *      Performs a preorder traversal on the BST.
 */
void BST_traversePreorder(BST_Node* root)

/**
 *  BST_traversePostorder
 *
 *      Performs a postorder traversal on the BST.
 */
void BST_traversePostorder(BST_Node* root)

/**
 *  BST_delete
 *
 *      Removes the node with the given value from the tree.
 *  Assumes unique elements. Otherwise may need to consider
 *  alternatives, like deleting all such nodes or only the first
 *  one encountered.
 */
void BST_delete(BST_Node* root, int value);

/**
 *  BST_min
 *
 *      Finds the smallest value in the BST.
 */
int BST_min(BST_Node* root);

/**
 *  BST_max
 *
 *      Finds the largest value in the BST.
 */
int BST_max(BST_Node* root);

#endif /* BINARY_SEARCH_TREE_H */
