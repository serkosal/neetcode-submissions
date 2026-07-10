class Solution {
public:
    // pos -> res
    int rob(vector<int>& nums) {
        const int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);

        nums[sz - 3] += nums[sz - 1];

        for (int i = sz - 4; i >= 0; --i)
            nums[i] += max(
                nums[i + 2], 
                nums[i + 3]
            );
        return max(nums[0], nums[1]);
    }
};
