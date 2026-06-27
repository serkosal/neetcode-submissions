class Solution {
public:
    vector<TreeNode*> pathFind(TreeNode *root, TreeNode *f)
{
    queue<pair<TreeNode*, vector<TreeNode*>>> q; q.push({root, {}});
    while (!q.empty())
    {
        auto [node, vec] = q.front(); q.pop();
        if (!node) continue;

        vec.push_back(node);
        if (node == f) return vec;
        
        q.push({node->left, vec});
        q.push({node->right, vec});
    }

    return {};
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    auto p1 = pathFind(root, p),
         p2 = pathFind(root, q);

    auto i1 = p1.begin(), i2 = p2.begin();
    auto last = vector<TreeNode *>::const_iterator(nullptr);
    for (;
         i1 < p1.end() && i2 < p2.end() && (*i1)->val == (*i2)->val;
         ++i1, ++i2)
        last = i1;

    return *last;
}
};
