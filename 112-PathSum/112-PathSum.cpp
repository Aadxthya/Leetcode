// Last updated: 9/16/2025, 9:53:54 AM
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;

        // If leaf node, check if path sum equals target
        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        // Recurse on children
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
