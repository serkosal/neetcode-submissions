class Solution {
public:
    int countComponents(int n, const vector<vector<int>>& edges) {
        int res = 0;
        using Component = unordered_set<int>;
        unordered_map<int, Component*> node_2_comp; 
        unordered_set<int> visited; for (int i = 0; i < n; ++i) visited.insert(i);
        for (const auto& edge : edges) {
            
            const int a = edge[0], b = edge[1];
            visited.erase(a); visited.erase(b);
            Component *a_comp = node_2_comp[a], *b_comp = node_2_comp[b];
            if (a_comp && b_comp && a_comp != b_comp) {
                for (int b_node: *b_comp) {
                    a_comp->insert(b_node);
                    node_2_comp[b_node] = a_comp;
                }
                delete b_comp;
                --res;
            }
            a_comp = a_comp ? a_comp : b_comp;
            if (!a_comp) {
                a_comp = new Component;
                ++res;
            }
            a_comp->insert({a, b});
            node_2_comp[a] = node_2_comp[b] = a_comp;
        }
        return res + visited.size();
}

};
