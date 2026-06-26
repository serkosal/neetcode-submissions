class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int num : nums)
            hash[num] = 1;

        int max_len = 0;
        for (int num : nums) 
            for (int i = num, sz = 1; hash.contains(i); --i, ++sz)
                if (sz > max_len) max_len = sz;

        return max_len;
    }
};
