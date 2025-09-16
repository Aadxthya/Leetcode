// Last updated: 9/16/2025, 9:51:33 AM
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
  int size(ListNode* head) {
        int count = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            tmp = tmp->next;
            count++;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL)
            return head;
        int length = size(head);
        ListNode * tmp = head;
        for(int i = 1; i <= k-1; i++){
            tmp= tmp->next;
        }
        ListNode * tmp2 = head;
        for(int i = 1; i <= length - k ; i++){
            tmp2= tmp2->next;
        }
        cout<< tmp2->val;
       swap(tmp->val,tmp2->val);
        return head;
    }
};