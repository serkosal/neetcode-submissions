class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());

        int max_len = 0;
        for (int num : nums) {
            if (uset.contains(num - 1)) continue;

            int cur_len = 1;
            while(uset.contains(num + cur_len)) 
                ++cur_len;
            max_len = max(max_len, cur_len);
        }

        return max_len;
    }
};
