class Solution {
public:
    int maxArea(const vector<int>& heights) {
        int max_area = 0;
        for (
            auto l = heights.begin(), r = heights.end() - 1;
            l < r && l < heights.end() && r >= heights.begin();
        ) {
            vector<int>::const_iterator min_ptr;
            if (*l < *r) min_ptr = l;
            else         min_ptr = r;
            const int height = *min_ptr,
                width = r - l;
            max_area = max(max_area, width * height);

            if (l == min_ptr) ++l;
            if (r == min_ptr) --r;
        }

        return max_area;
    }
};
