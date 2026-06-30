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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = {};
        if (!root) return {};
        stack<pair<TreeNode*, bool>> st; st.push({root, false});
        while(st.size()) {
            auto [node, is_visited] = st.top(); st.pop();

            if (is_visited) res.push_back(node->val);
            else {
                if (node->right) st.push({node->right, false});
                st.push({node, true});
                if (node->left) st.push({node->left, false});
            }
        }

        return res;
    }
};