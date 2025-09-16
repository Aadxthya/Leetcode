// Last updated: 9/16/2025, 9:48:54 AM
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* current = head;
        ListNode* dummy = head;

        int sum = 0;

        while (current != nullptr) {
            if (current->val == 0) {
                head->val = sum; // Assign the sum to the current head node
                if (current->next == nullptr) {
                    delete head->next;
                    head->next = nullptr; // Ensure the last node points to nullptr
                    break;
                }
                head = head->next; // Move head to the next node
                sum = 0; // Reset sum for the next sequence
            } else {
                sum += current->val;
            }
            current = current->next;
        }

        return dummy;
    }
};