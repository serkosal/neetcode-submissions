class Solution {
public:
    int findMin(vector<int> &nums) 
    {
                int n = nums.size();
        int l = 0, r = n-1;
        while (l < r)
        {
            int m = (r - l) / 2 + l;

            if (nums[l] <= nums[m] && nums[m] < nums[r])
                return nums[l];
            else if (nums[m] < nums[r] && nums[r] < nums[l])
                r = m;
            else if (nums[r] < nums[l] && nums[l] < nums[m])
                l = m;
            else ++l;
        }

        return nums[l];
    }
};
