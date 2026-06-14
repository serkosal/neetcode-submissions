class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        //  0  1  2  3  4  5  6  n = 7
        //  1  2  1  0 [4  2  6]

        int n = nums.size();
        vector<int> res(n - k + 1);
        for (int i = 0; i <= n - k; ++i)
        {
            int max = -1001;
            for (int j = 0; j < k; ++j)
                if (nums[i + j] > max)
                    max = nums[i + j];
            res[i] = max;
        }    

        return res;
    }
};
