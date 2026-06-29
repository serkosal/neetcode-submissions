class Solution {
public:
    string minWindow(const string& s, const string& t) {
        string_view res = ""; int min_val = s.size();

        multiset<char> h(t.begin(), t.end());
        for (auto l = s.begin(), e = s.end() - std::min(1, int(h.size())); 
            l <= e; 
            ++l
        ) {
            while (l <= e && !h.contains(*l)) ++l;
            for (auto [r, hh] = tuple(l, h); 
                 r < s.end() && r - l < min_val;
                 ++r
            ) {
                if (hh.contains(*r)) hh.erase(hh.find(*r));

                if (hh.empty()) min_val = (res = {l, r + 1}).size();
            } 
        }
        return string(res);
    }
};
