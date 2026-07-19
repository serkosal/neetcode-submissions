class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> memo;
        const int mx = nums.size();
        for (int num : nums)
            memo.insert(num);

        for (int i = 0; i < mx; ++i) 
            if (!memo.contains(i)) return i;
        
        return mx;
    }
};
