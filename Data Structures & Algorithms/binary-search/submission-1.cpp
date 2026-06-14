class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int l = 0, r = n, cur;
        while (l <= r)
        {
            int cur = l + (r - l) / 2;
            if (nums[cur] == target) return cur;
            else if (nums[cur] < target) l = cur + 1;
            else r = cur - 1;
        }

        return -1;
    }
};
