class Solution {
public:
    int carFleet(
        int target, 
        const vector<int>& pos, 
        const vector<int>& vel
    ) {
        vector<pair<int, int>> m; m.reserve(pos.size());
        for (int i = 0; i < pos.size(); ++i)
            m.push_back({pos[i], vel[i]});
        sort(m.begin(), m.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first;
        });

        stack<float> st;
        for (auto it = m.end() - 1; it >= m.begin(); --it) {
            float time = float(target - it->first) / it->second;
            if ((st.size() && time > st.top()) || st.empty()) 
                st.push(time);
        }
            
        return st.size();
    }
};
