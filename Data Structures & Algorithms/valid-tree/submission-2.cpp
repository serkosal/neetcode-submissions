class Solution {
    public:
        struct GraphNode {
        unordered_set<int> children;
        GraphNode() = default;
    };

    struct DFS_Traversal {
        int cur;
        unordered_set<int> visited;
        int prev = -1;
    };

    bool validTree(const int n, const vector<vector<int>>& edges) {
        vector<GraphNode> nodes(n);

        for (const auto& edge : edges) {
            const int a = edge[0], b = edge[1];
            nodes[a].children.insert(b);
            nodes[b].children.insert(a);
        }

        int visited_c = 0;
        stack<DFS_Traversal> to_visit; 
        to_visit.push({0, {}});
        while(to_visit.size()) {
            auto [cur, visited, prev] = to_visit.top(); to_visit.pop();
            visited.insert(cur);
            ++visited_c;

            for (auto child : nodes[cur].children) {
                if (child == prev) continue;
                if (visited.contains(child)) return false;
                to_visit.push({child, visited, cur});
            }
        }

        return visited_c == nodes.size();
    }

};
