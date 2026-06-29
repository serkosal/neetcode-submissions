class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0}; res.reserve(n + 1);

        for (int i = 1; i <= n; ++i) 
            res.push_back(res[i - std::pow(2, int(log2(i)))] + 1);

        return res;
    }
};
