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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int max_depth = 1;
        while (!st.empty()) {
            const auto [node, depth] = st.top(); st.pop();
            if (!node) continue;
            if (depth > max_depth) max_depth = depth;
            st.push({node->left, depth + 1}); 
            st.push({node->right, depth + 1});
        }

        return max_depth;
    }
};
