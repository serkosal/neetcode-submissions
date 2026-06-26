class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());

        int max_len = 0;
        for (int num : nums) 
            for (int i = num, sz = 1; uset.contains(i); --i, ++sz)
                if (sz > max_len) max_len = sz;

        return max_len;
    }
};
