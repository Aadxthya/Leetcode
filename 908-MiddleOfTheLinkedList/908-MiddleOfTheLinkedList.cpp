// Last updated: 9/16/2025, 9:50:33 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(!head || !(head-> next))
        return head;


        ListNode* node = head;
        ListNode* node2 = head;
        

while (node2 && node2->next) {
    node = node->next;
    node2 = node2->next->next;
}
        
    return node;
    }
};