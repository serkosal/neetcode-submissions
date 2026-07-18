class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        const int sz = nums.size();
        if (sz <= 1) return sz;
        int res = 1;
        vector<int> dp(sz, 1);
        for (int l = sz - 2; l >= 0; --l) {
            for (int r = l + 1; r < sz; ++r) {
                const int nr = nums[r], nl = nums[l]; 
                if (nr > nl) {
                    dp[l] = std::max(dp[l], dp[r] + 1);
                    res = std::max(res, dp[l]);
                }
            }
        }

        return res;
    }
};
