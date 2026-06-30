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

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        for (
            auto [cur, st] = tuple(root, stack<TreeNode*>{});
            cur || st.size();
            cur = cur->right
        ) {
            for (; cur; cur = cur->left)
                st.push(cur);

            cur = st.top(); st.pop();

            if (prev && prev->val >= cur->val) return false;
            prev = cur;
        }

        return true;
    }
};
