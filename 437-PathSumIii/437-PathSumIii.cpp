// Last updated: 9/16/2025, 9:51:50 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<long long , int> mpp;

        mpp[0] = 1;

        return dfs(root,0, mpp, targetSum);

    }




    int dfs(TreeNode* root, long long sum, unordered_map<long long , int>& mpp, int targetSum ){

        if(!root) return 0;

        int count = 0 ;
        sum += root->val;

        count += mpp[ sum  - targetSum];

        mpp[sum]++;


        count += dfs(root->left, sum, mpp, targetSum);
        count += dfs(root->right, sum, mpp, targetSum);

                mpp[sum]--;

                    return count;



    }
};