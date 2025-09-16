// Last updated: 9/16/2025, 9:54:17 AM
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0); // dummy node before head
        dummy->next = head;

        ListNode* prev = dummy;  // node before the duplicate sequence
        ListNode* curr = head;

        while (curr) {
            // Check for duplicates
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                // Skip all nodes with this duplicate value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                prev->next = curr; // remove all duplicates
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
