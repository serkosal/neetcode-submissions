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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res = {};
        for (
            stack q{deque{root}}; 
            q.size();
        ) {
            auto cur = q.top(); q.pop(); 

            res.push_back(cur->val); 
            if (cur->right) q.push(cur->right);
            if (cur->left) q.push(cur->left);
        }

        return res;
    }
};