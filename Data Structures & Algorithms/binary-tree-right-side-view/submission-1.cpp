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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> res = {};
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> new_q;

            TreeNode* last = nullptr;
            while (!q.empty()) {
                auto el = q.front(); q.pop();
                if (!el) continue;

                last = el;
                if (el->left) new_q.push(el->left);
                if (el->right) new_q.push(el->right);
            }
            if (last) res.push_back(last->val);

            q = new_q;
        }

        return res;
    }
};
