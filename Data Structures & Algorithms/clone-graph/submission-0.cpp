class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* res = new Node;

        unordered_map<Node*, Node*> node_mapping; // original Node -> cloned Node
        queue to_clone(deque<pair<Node*, Node*>>{{node, res}});
        while (to_clone.size()) {
            auto [from, where] = to_clone.front(); to_clone.pop();

            where->val = from->val;
            for (Node* neighbor : from->neighbors) {
                if (!neighbor) continue;

                if (!node_mapping[neighbor]) {
                    node_mapping[neighbor] = new Node;
                    to_clone.push({neighbor, node_mapping[neighbor]});
                }

                where->neighbors.push_back(node_mapping[neighbor]);
            }    
        }

        return res;
    }
};
