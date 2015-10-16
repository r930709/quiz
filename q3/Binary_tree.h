#ifndef _TREE_Node_H
#define _TREE_Node_H

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} Tree_Node;

Tree_Node *Build_Binary_Tree(Tree_Node *root);
void Inorder_traversal(Tree_Node *root);
#endif
