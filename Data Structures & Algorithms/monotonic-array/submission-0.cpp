class Solution {
public:
    bool isMonotonic(const vector<int>& nums) {
        for (auto [i, sz, is_inc, is_dec] = tuple{1, nums.size(), true, true}; 
             i < sz; 
             ++i
        ) {
            if (nums[i - 1] > nums[i]) 
                is_inc = false;

            if (nums[i - 1] < nums[i])
                is_dec = false;

            if (!is_inc && !is_dec) 
                return false;
        }

        return true;
    }
};