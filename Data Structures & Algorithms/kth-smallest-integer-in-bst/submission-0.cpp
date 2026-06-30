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
    int kthSmallest(TreeNode* root, int k) {
        for (
            auto [i, cur, st] = tuple(0, root, stack<TreeNode*>{});
            cur || st.size();
            cur = cur->right
        ) {
            for (; cur; cur = cur->left)
                st.push(cur);

            cur = st.top(); st.pop();
            
            if (++i == k) return cur->val;
        }

        return 0;
    }
};
