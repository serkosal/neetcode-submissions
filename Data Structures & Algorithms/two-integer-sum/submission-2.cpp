class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // target - nums[i], pos
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) 
            m[target - nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i)
            if (m.contains(nums[i]) && m[nums[i]] != i)
                return {i, m[nums[i]]};

        return {-1, -1};
    }
};
