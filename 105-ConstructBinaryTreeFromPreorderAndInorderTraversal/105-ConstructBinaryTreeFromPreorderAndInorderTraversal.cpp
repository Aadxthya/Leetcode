// Last updated: 9/16/2025, 9:53:56 AM
class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store index of each value in inorder for O(1) lookup
        for(int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if(inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderIndexMap[rootVal];

        root->left = build(preorder, inStart, inorderIndex - 1);
        root->right = build(preorder, inorderIndex + 1, inEnd);

        return root;
    }
};