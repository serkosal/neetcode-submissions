class Solution {
public:
    unordered_map<TreeNode*, int> DFS_hash;

    int dfs_max_path_len(TreeNode* root) {
        if (!root) return 0;
        if (DFS_hash.contains(root)) return DFS_hash[root];

        queue<pair<TreeNode*, int>> q; q.push({root, root->val});

        int res = 0;
        while (q.size()) {
            auto [node, path_len] = q.front(); q.pop();
            res = max(res, path_len);
            
            if (node->left) 
                q.push({node->left, path_len + node->left->val}); 
            if (node->right)
                q.push({node->right, path_len + node->right->val});
        }

        return DFS_hash[root] = res;
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val;

        if (root->left)
            res = max(res, res + dfs_max_path_len(root->left));
        if (root->right)
            res = max(res, res + dfs_max_path_len(root->right));

        if (root->left)
            res = max(res, maxPathSum(root->left));
        if (root->right)
            res = max(res, maxPathSum(root->right));

        return res;
    }
};
