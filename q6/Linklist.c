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


ListNode *Build_Linklist(ListNode *head,int size)
{

    ListNode *ptr = NULL;
    int i;
    ptr = (ListNode *)malloc(sizeof(ListNode));
    head = ptr;
    for(i=1; i<=(size-1); i++) {
        ptr->data = i;
        ptr->next = (ListNode *)malloc(sizeof(ListNode));
        ptr = ptr->next;
    }
    ptr->data = i;
    ptr->next = NULL;


    return(head);
}

void Linklist_Traversal(ListNode *head)
{

    if(head == NULL) {
        return;
    } else {
        ListNode *traversal = head;
        while(traversal!=NULL) {
            printf("\t%d",traversal->data);
            traversal = traversal->next;
        }

    }

}

