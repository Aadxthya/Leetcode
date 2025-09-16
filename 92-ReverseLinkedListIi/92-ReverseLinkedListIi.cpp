// Last updated: 9/16/2025, 9:54:08 AM
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* forw = NULL;
        ListNode* prev = NULL;
        ListNode* start = NULL; // Pointer to the node before the left position
        ListNode* end = NULL; // Pointer to the node at the right position
        int count = 1; // Initialize count to 1 since we start counting from the first node

        // Move to the left position
        while (count < left) {
            start = temp; // Update start pointer
            temp = temp->next; // Move to the next node
            count++;
        }

        // Initialize end pointer
        end = temp;

        // Reverse the nodes between positions left and right
        while (count <= right) {
            forw = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forw;
            count++;
        }

        // Connect the reversed section with the rest of the list
        if (start != NULL) {
            start->next = prev;
        } else {
            head = prev; // Update head if the reversal starts from the beginning
        }
        end->next = temp;
        return head;
    }
};
