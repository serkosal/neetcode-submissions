class Solution {
public:
    // pos -> res
    int rob(vector<int>& nums) {
        int res = 0;
        const int sz = nums.size();
        for (int i = sz - 1; i >= 0; --i)
            res = max(
                res, 
                nums[i] += max(
                    i + 2 < sz ? nums[i + 2] : 0, 
                    i + 3 < sz ? nums[i + 3] : 0
                )
            );

        return res;
    }
};
