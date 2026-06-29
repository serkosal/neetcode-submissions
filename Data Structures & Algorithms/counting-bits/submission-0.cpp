class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0};

        for (int i = 1; i <= n; ++i) {
            const int index = i - std::pow(2, int(log2(i)));
            res.push_back(res[index] + 1);
        }

        return res;
    }
};
