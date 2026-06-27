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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> res = {};
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> new_q;
            res.push_back({});
            while (!q.empty()) {
                auto el = q.front(); q.pop();
                if (!el) continue;

                res.back().push_back(el->val);
                if (el->left) new_q.push(el->left);
                if (el->right) new_q.push(el->right);
            }

            q = new_q;
        }

        return res;
    }
};
