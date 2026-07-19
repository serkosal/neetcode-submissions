class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        const int sz = nums.size();
        int expected_sum = sz * (sz + 1) / 2;
        for (int num : nums) 
            expected_sum -= num;
        
        return expected_sum;
    }
};
