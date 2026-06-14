#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; ++i )
    {
        if (st.count(nums[i])) return true;
        else (st.insert(nums[i]));
    }

    return false;
    }
};
