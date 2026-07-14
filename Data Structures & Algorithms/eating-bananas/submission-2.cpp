class Solution {
public:
    bool test(vector<int>& piles, int h, int k) {
        const int sz = piles.size();
        int elasted_time = 0;
        for (int i = 0; i < sz; ++i) {
            elasted_time += ceil(piles[i] / double(k));
            if (elasted_time > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int res = 0;
        int mx = 0, sum = 0;
        for (int num : piles) {
            mx = max(mx, num);
            sum += num;
        }
        int mn = 1, mxx = mx;
        while (mn <= mxx) {
            int m = mn + (mxx - mn) / 2;

            if (test(piles, h, m)) {
                res = m;
                mxx = m - 1;
            }
            else mn = m + 1;
        }

        return res;
    }
};
