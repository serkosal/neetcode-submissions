class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int max = 0, n = heights.size(), l = 0, r = n - 1;
        while (l < r)
        {
            int n_max = min(heights[l], heights[r]) * (r - l);
            if (n_max > max) max = n_max;

            if (heights[l] < heights[r])
                ++l;
            else
                --r;
        }

        return max;
    }
};
