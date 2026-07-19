struct PairHasher {
    size_t operator()(const pair<int, int>& p) const noexcept {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);

        return h1 ^ (h2 << 1);
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, PairHasher> memo;
    int longestCommonSubsequence(const string &t1, const string &t2, int st1 = 0, int st2 = 0) {
        const int sz1 = t1.size(), sz2 = t2.size();  
        if (st1 >= sz1 || st2 >= sz2 || !sz1 || !sz2)
            return 0;
        if (memo.contains({st1, st2}))
            return memo[{st1, st2}];

        int res = 0;
        if (t1[st1] == t2[st2])
            res = 1 + longestCommonSubsequence(t1, t2, st1 + 1, st2 + 1);
        else
            res = std::max(
                longestCommonSubsequence(t1, t2, st1 + 1, st2),
                longestCommonSubsequence(t1, t2, st1, st2 + 1)
            );

        memo[{st1, st2}] = res;
        return res;
    }

};
