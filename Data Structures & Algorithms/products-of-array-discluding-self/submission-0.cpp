class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n, 1);
        int l_prev = 1, r_prev = 1;

        for (int i = 1; i < n; ++i)
        {   
            int l, r;
            l = l_prev * nums[i - 1];
            r = r_prev * nums[n - i];

            res[i]          *= l;
            res[n - 1 - i]  *= r;

            l_prev = l;
            r_prev = r;
        }

        return res;
    }
};
