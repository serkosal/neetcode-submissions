class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st; st.push({root, 1});
        int max_depth = 0;
        while (!st.empty()) {
            const auto [node, depth] = st.top(); st.pop();
            if (!node) continue;
            if (depth > max_depth) max_depth = depth;
            st.push({node->left, depth + 1}); 
            st.push({node->right, depth + 1});
        }
        return max_depth;
    }


    bool isBalanced(TreeNode* root) {
        
        stack<TreeNode*> st; st.push(root);

        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            if (!cur) continue;

            if (abs(maxDepth(cur->left) - maxDepth(cur->right)) > 1) 
                return false;

            st.push(cur->left); st.push(cur->right);
        }

        return true;
    }
};
