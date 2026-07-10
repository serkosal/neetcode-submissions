class Solution {
public:
    // pos -> res
    int rob(vector<int>& nums) {
        const int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);

        int res = 0;
        for (int i = sz - 1; i >= 0; --i)
            nums[i] += max(
                i + 2 < sz ? nums[i + 2] : 0, 
                i + 3 < sz ? nums[i + 3] : 0
            );

        return max(nums[0], nums[1]);
    }
};
