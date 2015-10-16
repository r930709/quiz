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

Tree_Node *Build_Binary_Tree(Tree_Node *root)
{

    Tree_Node *Node2 = NULL,*Node3 = NULL,*Node4 = NULL,*Node5 = NULL,*Node6 =NULL;
    if(root == NULL) {

        root = (Tree_Node *)malloc(sizeof(Tree_Node));
        root->value = 1;

        root->left = (Tree_Node *)malloc(sizeof(Tree_Node));
        root->right = (Tree_Node *)malloc(sizeof(Tree_Node));

        Node2 = root->left;
        Node2->value = 2;
        Node2->left = (Tree_Node *)malloc(sizeof(Tree_Node));
        Node2->right = (Tree_Node *)malloc(sizeof(Tree_Node));

        Node3 = Node2->left;
        Node3->value = 3;
        Node3->left = NULL;
        Node3->right = NULL;

        Node4 = Node2->right;
        Node4->value = 4;
        Node4->left = NULL;
        Node4->right = NULL;

        Node5 = root->right;
        Node5->value = 5;
        Node5->left = NULL;
        Node5->right = (Tree_Node *)malloc(sizeof(Tree_Node));

        Node6 = Node5->right;
        Node6->value = 6;
        Node6->left = NULL;
        Node6->right = NULL;

    }
    return(root);
}

void Inorder_traversal(Tree_Node *root)
{

    if(root == NULL) {
        return;
    } else {

        Inorder_traversal(root->left);
        printf("\t%d",root->value);
        Inorder_traversal(root->right);

    }

}

