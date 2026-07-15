class Solution {

public:
    int maxProduct(span<int> nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = i; j < nums.size(); ++j) {
                product *= nums[j];
                res = max(res, product);
            }
        }

        return res;
    }
};
