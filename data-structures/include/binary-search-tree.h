#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
/**
 * binary-search-tree.h
 *
 * Author: David Piper
 *
 *      The purpose of this file is to provide
 *  definitions for the binary search tree module.
 */

/**
 * TODO:
 *  implement the following:
 *
 *      * search/contains
 *      * traversal:
 *          - inorder
 *          - preorder
 *          - postorder
 *      * deletion
 *      * insert
 *      * min/max
 */

struct BST_Node {
    struct BST_Node* mLeft;
    struct BST_Node* mRight;
    int mValue;
};

typedef BST_Node BST_Node;

int BST_contains(int value);
void BST_inorderTraverse();
void BST_preorderTraverse();
void BST_postorderTraverse();
void BST_delete(int value);

#endif /* BINARY_SEARCH_TREE_H */
