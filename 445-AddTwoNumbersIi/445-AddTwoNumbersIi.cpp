// Last updated: 9/16/2025, 9:51:49 AM
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
    ListNode* Helper(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;

        // Push all nodes of l1 into stack1
        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        // Push all nodes of l2 into stack2
        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = nullptr;
        int carry = 0;

        // Add digits with carry
        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int digit1 = !stack1.empty() ? stack1.top() : 0;
            int digit2 = !stack2.empty() ? stack2.top() : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            // Create new node and add at front
            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;

            if (!stack1.empty()) stack1.pop();
            if (!stack2.empty()) stack2.pop();
        }

        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return Helper(l1, l2);
    }
};