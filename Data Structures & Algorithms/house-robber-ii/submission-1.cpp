class Solution {
public:
    int robSimple(vector<int> nums) {
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

    int rob(const vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        return max(
            robSimple({nums.begin(), nums.end() - 1}),
            robSimple({nums.begin() + 1, nums.end()})
        );
    }
};
