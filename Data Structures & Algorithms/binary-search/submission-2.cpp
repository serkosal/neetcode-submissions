class Solution {
public:
    int search(const vector<int>& n, int target) {
        int l = 0, r = n.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (n[m] == target) return m;
            
            if (n[m] > target) r = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};
