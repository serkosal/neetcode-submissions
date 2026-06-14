class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto sz = nums.size();
        if (sz == 0) return {};

        vector<int> prefix(sz, 1), postfix(sz, 1);
        for (size_t i = 1; i < sz; ++i) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
            postfix[sz - i - 1] = nums[sz - i] * postfix[sz - i];
        }

        for (size_t i = 0; i < sz; ++i)
            postfix[i] *= prefix[i];
            
        return postfix;
    }
};
