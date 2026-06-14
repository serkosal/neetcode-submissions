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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if (!root) return res;

        res.push_back(root->val);

        queue<TreeNode*> to_visit; 
        to_visit.push(root);
        while(to_visit.size())
        {
            queue<TreeNode*> discovered;
            for (TreeNode* cur; to_visit.size(); to_visit.pop())
            {
                cur = to_visit.front();
                if (cur->left)  discovered.push(cur->left);
                if (cur->right) discovered.push(cur->right);
            }
            if (discovered.size())
                res.push_back(discovered.back()->val);

            to_visit = discovered;
        }

        return res;    
    }
};
