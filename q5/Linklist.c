#include<stdio.h>
#include<stdlib.h>
#include "Linklist.h"

/*--------Linklist Structure
-
-
-
-
-
-
*/


ListNode *Build_Linklist(ListNode *head,int size,int cycle_begin)
{

    ListNode *ptr = NULL,*begin = NULL;
    int i;
    ptr = (ListNode *)malloc(sizeof(ListNode));
    head = ptr;
    for(i=1; i<=(size-1); i++) {
        ptr->data = i;
        ptr->next = (ListNode *)malloc(sizeof(ListNode));
        if(i==cycle_begin) {
            begin = ptr;
        }
        ptr = ptr->next;
    }
    ptr->data = i;
    ptr->next = begin;


    return(head);
}

void Linklist_Traversal(ListNode *head,int size)
{

    if(head == NULL) {
        return;
    } else {
        int i;
        ListNode *traversal = head;
        while(i<=size && traversal!=NULL) {
            printf("\t%d",traversal->data);
            traversal = traversal->next;
            i++;
        }

    }

}

