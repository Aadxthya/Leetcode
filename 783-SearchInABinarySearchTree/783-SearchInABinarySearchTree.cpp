// Last updated: 9/16/2025, 9:50:58 AM
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        if(val < root->val) 
            return searchBST(root->left,val);
        else 
            return searchBST(root->right,val);
    }
};