#include<stdio.h>
#include<stdlib.h>
#include "Linklist.h"

ListNode *ReverseAll(ListNode *m,ListNode *n)
{
    ListNode *reverse_head = NULL;
    if(m == n) {
        return(m);
    }
    reverse_head = ReverseAll(m->next,n);
    reverse_head->next = m;
    return(m);

}
ListNode *Reversebetween_Recursive(ListNode *head,int m,int n)
{
    ListNode *mNode = NULL,*nNode = NULL,*nNext = NULL,*mPre = NULL,*reverse_bottom = NULL;
    ListNode *ptr = head;
    int counter = 1;
    while(counter < m) {
        if(counter == (m-1)) {
            mPre = ptr;
        }
        ptr = ptr->next;
        counter++;

    }
    mNode = ptr;

    while(counter < n) {
        ptr = ptr->next;
        counter++;
    }
    nNode = ptr;
    nNext = nNode->next;
    reverse_bottom  = ReverseAll(mNode,nNode);
    reverse_bottom->next = nNext;
    if(m!=1) {
        mPre->next = nNode;
        return(head);
    } else if(m==1) {
        return( nNode);
    }
}
