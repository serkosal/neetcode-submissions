class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};
