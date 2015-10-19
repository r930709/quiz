#include<stdio.h>

#include<stdlib.h>
#include "Binary_tree.h"

/*--------Tree Structure
-             1
-           /   \
-          2     5
-         / \   / \
-        3   4 N   6
-       / \ / \   / \
       N  NN   N  N  N
*/


void Flatten_Iterative(Tree_Node *root)
{
    if(root == NULL) {
        return;
    } else {
        Tree_Node *traversal_root = root;
        while(traversal_root) {
            Tree_Node *temp_right = traversal_root->right;
            if(traversal_root->left) {
                Tree_Node *become_right_right_bottom = traversal_root->left;
                while(become_right_right_bottom->right) {
                    become_right_right_bottom = become_right_right_bottom->right;
                }
                become_right_right_bottom->right = temp_right;
                traversal_root->right = traversal_root->left;
                traversal_root->left = NULL;

            }
            traversal_root = traversal_root->right;
        }
    }

}

