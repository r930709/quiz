#ifndef _LIST_Node_H
#define _LIST_Node_H

typedef struct listnode {
    int data;
    struct listnode *next;
} ListNode;

ListNode *Build_Linklist(ListNode *head,int size);
void Linklist_Traversal(ListNode *head);
#endif
