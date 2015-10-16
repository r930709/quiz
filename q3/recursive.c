#include<stdio.h>
#include<stdlib.h>
#include "Binary_tree.h"

/*--------Tree Structure
-            1
-           / \
-          2   5
-         / \   \
-        3   4   6
-
*/


Tree_Node *Flatten_Recursive(Tree_Node *root)
{

    if(root == NULL) {
        return NULL;
    }
    if(root->right) {
        root->right = Flatten_Recursive(root->right);
    }
    if(root->left) {
        Tree_Node *tmp_right = root->right;
        root->right = Flatten_Recursive(root->left);
        Tree_Node *right_bottom = root->right;
        while(right_bottom->right) {
            right_bottom = right_bottom->right;
        }
        right_bottom -> right= tmp_right;
        root->left = NULL;
    }


    return( root );
}

