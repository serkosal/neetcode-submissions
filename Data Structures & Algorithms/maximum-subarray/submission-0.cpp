class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = numeric_limits<int>::min(), sum = 0;
        for (int num : nums) {
            sum += num;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }

        return res;
    }
};
