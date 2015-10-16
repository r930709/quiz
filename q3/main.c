#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "Binary_tree.h"



int main()
{

    Tree_Node *root = NULL;
    root = Build_Binary_Tree(root);
    Inorder_traversal(root);
    printf("\n");
    Flatten_Recursive(root);
    Inorder_traversal(root);
    printf("\n");
    return(0);
}
