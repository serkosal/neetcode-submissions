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
};
