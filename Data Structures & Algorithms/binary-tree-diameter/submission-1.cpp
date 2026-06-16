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

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;

        stack<TreeNode*> st; st.push(root);

        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            if (!cur) continue;
            int cur_diameter = maxDepth(cur->left) + maxDepth(cur->right);
            if (cur_diameter > max_diameter) max_diameter = cur_diameter;

            st.push({cur->left}); st.push({cur->right});
        }

        return max_diameter;
    }
};
