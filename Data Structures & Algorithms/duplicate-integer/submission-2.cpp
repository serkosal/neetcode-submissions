class Solution {
public:
    bool hasDuplicate(const vector<int>& nums) {
        unordered_map<int, int> hash;

        for (int num : nums) 
            if (++hash[num] > 1) return true;

        return false;
    }
};