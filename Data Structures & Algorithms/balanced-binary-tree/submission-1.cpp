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
    int depth(TreeNode* root)
    {
        if (!root) return -1;

        return 1 + max(depth(root->left), depth(root->right));
    }

    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;

        bool res = abs(depth(root->left) - depth(root->right)) <= 1;
        if (root->left ) res *= isBalanced(root->left);
        if (root->right) res *= isBalanced(root->right);

        return res;  
    }
};
