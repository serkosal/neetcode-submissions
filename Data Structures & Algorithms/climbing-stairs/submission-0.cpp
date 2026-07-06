class Solution {
public:
    int climbStairs(int n) {
        int t0 = 0, t1 = 1, res = 0;
        for (; n >= 1; --n) {
            res = t0 + t1;
            t0 = t1;
            t1 = res;
        }

        return res;
    }
};
