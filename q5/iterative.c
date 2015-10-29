#include<stdio.h>
#include<stdlib.h>
#include "Linklist.h"

#define NEXT(x) (x = x->next)
#define NEXT2(x) (x = x->next->next)

ListNode *DetectCycle_Iterative(ListNode *head)
{
    ListNode *turtle = head; //1x
    ListNode *rabbit = head; //2x

    /*Detect_Cycle*/
    while(turtle && rabbit && rabbit->next) {
        NEXT(turtle);
        NEXT2(rabbit);
        if(turtle == rabbit) {
            break;
        }
    }
    if(!turtle || !rabbit || !(rabbit->next)) {
        return(NULL);
    }
    /*Find cycle begin
    meet point and head as the starting point,together with a forward speed,
    they will meet in the begin of the cycle.
    */
    ListNode *meet_point = turtle;
    ListNode *begin = head;
    while(meet_point && begin) {
        NEXT(meet_point);
        NEXT(begin);
        if(meet_point == begin) {
            return(meet_point);
        }
    }

}

