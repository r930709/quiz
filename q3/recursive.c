#include<stdio.h>
#include<stdlib.h>
#include "Binary_tree.h"

/*--------Tree Structure
-             1
-           /   \
-          2     5
-         / \   / \
-        3   4 N   6
-	/ \ / \   / \
.      N  N N  N N   N
*/


Tree_Node *Flatten_Recursive(Tree_Node *root)
{

    if(root == NULL) {
        return NULL;
    } else if(root->left) {
        Tree_Node *tmp_right = root->right;
        Tree_Node *become_right = Flatten_Recursive(root->left);
        Tree_Node *br_right_bottom = root->left; /*become_rigjt_right_bottom*/
        while(br_right_bottom->right) {
            br_right_bottom = br_right_bottom->right;
        }
        br_right_bottom->right= tmp_right;
        root->right = become_right;
        root->left = NULL;
    } else if(root->right) {
        root->right = Flatten_Recursive(root->right);
    }
    return( root );
}

