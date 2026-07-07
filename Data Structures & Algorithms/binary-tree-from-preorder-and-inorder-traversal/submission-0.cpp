class Solution {
public:
    TreeNode* buildTree(span<int> preorder, span<int> inorder) {
        const int sz = preorder.size();
        if (sz == 0 || sz != inorder.size()) return nullptr;

        auto root = new TreeNode(preorder[0]);
        
        int i = 0;
        for (; i < sz && inorder[i] != preorder[0]; ++i);
        root->left = buildTree(
            {preorder.begin() + 1, preorder.begin() + i + 1},
            {inorder.begin(), inorder.begin() + i}
        );
        root->right = buildTree(
            {preorder.begin() + i + 1, preorder.end()},
            {inorder.begin() + i + 1, inorder.end()}
        );

        return root;
    }
};
