// Last updated: 9/16/2025, 9:50:26 AM
class CBTInserter {
public:
    vector<TreeNode*> tree;

    // Constructor for CBTInserter
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size(); ++i) {
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }

    // Insert a new node with value 'v' and return the value of its parent
    int insert(int v) {
        int N = tree.size();
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        if (N % 2)
            tree[(N - 1) / 2]->left = node;
        else
            tree[(N - 1) / 2]->right = node;
        return tree[(N - 1) / 2]->val;
    }

    // Return the root of the tree
    TreeNode* get_root() {
        return tree[0];
    }
};
