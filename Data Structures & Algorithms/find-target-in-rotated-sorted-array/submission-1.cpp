class Solution {
public:
    int search(vector<int>& nums, int t) 
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (r - l) / 2 + l;

            if (nums[l] == t) return l;
            else if (nums[r] == t) return r;
            else if (nums[m] == t) return m;

            if (nums[l] < nums[m] && nums[m] < nums[r])
                t < nums[m] ? r = m : l = m; 
            else if (nums[m] < nums[r] && nums[r] < nums[l])
            {
                if (t < nums[m]) r = m;
                else if (t <= nums[r]) l = m;
                else r = m;
            }
            else if (nums[r] < nums[l] && nums[l] < nums[m])
            {
                if (t <= nums[r]) l = m + 1;
                else r = m;
            }
            else ++l;
        }

        return -1;
    }
};
