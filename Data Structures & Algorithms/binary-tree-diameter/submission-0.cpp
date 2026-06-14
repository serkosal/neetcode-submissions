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
    int height(TreeNode* root)
    {
        if (!root) return -1;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
       if (!root) return 0;
       int this_diameter = 2 + height(root->left) + height(root->right);
       int child_d = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));

       return max(this_diameter, child_d);
    }
};
