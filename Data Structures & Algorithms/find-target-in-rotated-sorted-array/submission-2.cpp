class Solution {
public:
    int search(const vector<int>& nums, int target) {
        auto l = 0; 
        for (
            auto r = nums.size() - 1;
            l < r;
        ) {
            auto m = l + (r - l) / 2; 
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target <= nums[m])
                    r = m;
                else l = m + 1;
            }
            else {
                if (nums[m + 1] <= target && target <= nums[r])
                    l = m + 1;
                else r = m;
            }
        }

        if (nums[l] == target) return l;
        else return -1;
    }
};
