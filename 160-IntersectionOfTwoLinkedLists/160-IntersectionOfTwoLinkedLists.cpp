// Last updated: 9/16/2025, 9:53:14 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
            return NULL;
        }
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1!=ptr2){
            if(ptr1!= NULL){
                ptr1= ptr1->next;
            }
            else{
                ptr1=headB;
            }
            if(ptr2!= NULL){
                ptr2= ptr2->next;
            }
            else{
                ptr2=headA;
            }
        }

    return ptr1;

        
        
    }
};