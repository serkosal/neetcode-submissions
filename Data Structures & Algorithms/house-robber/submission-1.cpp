class Solution {
public:
    // pos -> res
    int rob(vector<int>& nums) {
        int res = 0;
        const int sz = nums.size();
        for (int i = sz - 1; i >= 0; --i) {
            int next = i + 2 < sz ? nums[i + 2] : 0, 
                nnext = i + 3 < sz ? nums[i + 3] : 0;
            nums[i] += max(next, nnext);
            res = max(res, nums[i]);
        }

        return res;
    }
};
