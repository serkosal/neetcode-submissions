class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> memo;
        int mx = 0;
        for (int num : nums) {
            memo.insert(num);
            mx = max(mx, num);
        }
        for (int i = 0; i < mx; ++i) 
            if (!memo.contains(i)) return i;
        
        return mx + 1;
    }
};
