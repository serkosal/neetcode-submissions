class Solution {
public:

    // -6 -5 -4 -3 -2 -1 0 1 2 3 4 6, target = 0

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum > target)
                --r;
            else if (sum < target)
                ++l;
            else return {l + 1, r + 1};          
        }

        return {};
    }
};
