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
    TreeNode* invertTree(TreeNode* const root) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (!cur) continue;

            std::swap(cur->left, cur->right);
            q.push(cur->left); q.push(cur->right);
        };

        return root;
    }
};
