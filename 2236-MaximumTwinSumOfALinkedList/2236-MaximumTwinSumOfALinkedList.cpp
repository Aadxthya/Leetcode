// Last updated: 9/16/2025, 9:49:07 AM
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
    int pairSum(ListNode* head) {
        vector<int>nums;
        ListNode* temp=head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int l=0,h=nums.size()-1,maximum=INT_MIN;
        while(l<h){
            int x=nums[l]+nums[h];
            maximum=max(maximum,x);
            l++;
            h--;
        }
        return maximum;
        
    }
};