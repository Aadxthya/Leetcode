// Last updated: 9/16/2025, 9:53:28 AM
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
    bool hasCycle(ListNode *head) {

        if(head==NULL) return false;

    if(head->next==NULL) return false;
        ListNode* node = head;
        ListNode* node2 = head;
    

        while(node2 && node2->next){
            node = node->next;
            node2 = node2->next->next;
           if(node == node2){
            return true;
           }
           

        }
        return false;

        
    }
};