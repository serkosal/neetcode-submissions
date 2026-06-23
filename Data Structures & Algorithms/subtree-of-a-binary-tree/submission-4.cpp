class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> nodes_queue;
        
        for (
            nodes_queue.push({p, q});
            !nodes_queue.empty();
            nodes_queue.pop()
        ) {
            auto [n1, n2] = nodes_queue.front();
            
            if ((!n1 && n2) || (n1 && !n2)) 
                return false;

            if (n1 && n2) {
                if (n1->val != n2->val) 
                    return false;

                nodes_queue.push({n1->left, n2->left});
                nodes_queue.push({n1->right, n2->right});
            }
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;

        queue<TreeNode*> q;
        

        for (
            q.push(root);
            !q.empty();
        ) {
            auto r = q.front(); q.pop();

            if (!r) continue;

            if (r->val == subRoot->val && isSameTree(r, subRoot))
                return true;

            if (r->left) q.push(r->left); 
            if (r->right) q.push(r->right);
        }

        return false;
    }
};
