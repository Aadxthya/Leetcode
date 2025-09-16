// Last updated: 9/16/2025, 9:54:38 AM
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* node = head;
        int  count = 1;
        if (!head || !head->next || k == 0) return head;

        while(node-> next){
           count++;
           node = node -> next; 
        }

        node->next = head;

        k %= count ;
        int neww = count - k ;
        ListNode* nerw = head;
        for(int i = 0 ; i < neww - 1 ; i++){
           nerw =  nerw-> next;
        }
        
        ListNode* newhead = nerw -> next;
        nerw -> next = NULL;

    return newhead;
    }
};