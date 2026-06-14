class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        set<int> st;
        for (auto& num : nums) st.insert(num);

        int max = 0, cur_max = 1, prev_val = *st.begin();
        auto cur_it = ++st.begin();
        while ( cur_it != st.end() )
        {
            if (*cur_it - prev_val != 1)
            {
                if (cur_max > max) max = cur_max;

                cur_max = 1;
            }
            else ++cur_max;

            prev_val = *cur_it;
            ++cur_it;
        }

        if (cur_max > max) max = cur_max;
        return max;
    }
};
