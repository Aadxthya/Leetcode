// Last updated: 9/16/2025, 9:54:00 AM
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long p = LONG_MIN;
        long q = LONG_MAX;
        return dsp(root, p, q);
    }

    bool dsp(TreeNode* node, long min, long max) {
        if (node == NULL) return true;
        if (node->val <= min || node->val >= max) return false;
        return dsp(node->left, min, node->val) && dsp(node->right, node->val, max);
    }
};
