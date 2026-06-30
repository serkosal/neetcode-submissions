class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = {};
        for (
            auto [cur, st] = tuple(root, stack<TreeNode*>{});
            cur || st.size();
            cur = cur->right
        ) {
            for (; cur; cur = cur->left)
                st.push(cur);

            cur = st.top(); st.pop();

            res.push_back(cur->val);
        }

        return res;
    }
};