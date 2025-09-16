// Last updated: 9/16/2025, 9:53:27 AM
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr; // No cycle
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Detect cycle using Floyd's Tortoise and Hare algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break; // Cycle detected
        }
        
        // If fast reached end of list, no cycle exists
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        
        // Move slow pointer to head, keep fast at meeting point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Return the node where cycle starts
        return slow;
    }
};
