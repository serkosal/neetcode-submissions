class Solution {
public:
    int findMin(const vector<int> &nums) {
        auto l = nums.begin(), r = nums.end() - 1;

        while (l < r && *l > *r) {
            auto m = l + (r - l) / 2;
            
            if (*l > *m) r = m;
            else l = m + 1;
        }

        return *l;
    }
};
