struct GraphNode {
    int value;
    unordered_set<GraphNode*> children;

    GraphNode() = default;

    GraphNode(int value, const unordered_set<GraphNode*>& children = {}) 
    : value(value), children(children)
    {}

    bool operator==(const GraphNode& other) const noexcept {
        return this->value == other.value;
    }
};

namespace std {
    template<>
    struct hash<GraphNode> {
        size_t operator()(const GraphNode& node) const noexcept {
            return hash<int>{}(node.value);
        }
    };
};

class Solution {
public:
    bool canFinish(
        const int numCourses, 
        const vector<vector<int>>& prerequisites
    ) {
        unordered_map<int, GraphNode> nodes;
        set<const GraphNode*> to_visit;
        for (int i = 0; i < numCourses; ++i) {
            auto [it, inserted] = nodes.emplace(i, GraphNode{i});
            to_visit.insert(&it->second);
        }

        for (const auto& dep : prerequisites)
            nodes[dep[1]].children.insert(&nodes[dep[0]]);

        while(to_visit.size()) {
            auto src = to_visit.begin();

            // dfs
            stack<pair<const GraphNode*, 
                unordered_set<const GraphNode*>
            >> st; st.push({*src, unordered_set<const GraphNode*>{}});
            while (st.size()) {
                auto [cur, visited] = st.top(); st.pop();

                if (visited.contains(cur)) 
                    return false;
                visited.insert(cur);
                to_visit.erase(cur);

                for (const GraphNode* child : cur->children)
                    st.push({child, visited});
            }
        }

        return true;
    }
};
