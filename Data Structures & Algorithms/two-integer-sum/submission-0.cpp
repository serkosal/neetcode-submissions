#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> deltas;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int delta = target - nums[i];
            if (deltas.count(delta)) 
                return {deltas[delta], i};
            else
                deltas[nums[i]] = i;
        }

        return {0, 1};    
    }
};
