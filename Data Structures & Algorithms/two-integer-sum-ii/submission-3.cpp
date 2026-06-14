class Solution {
public:
    vector<int> twoSum(const vector<int>& n, int t) {
        int l = 0, r = n.size() - 1;

        while (l < r) {

            int sum = n[l] + n[r]; 
            if (sum == t) return {l + 1, r + 1};
            if (sum > t) --r;
            else ++l;
        }

        return {-1, -1};
    }
};
