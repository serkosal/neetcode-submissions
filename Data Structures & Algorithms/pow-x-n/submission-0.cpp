class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) return 0;
        if (x == 1.0) return 1;

        double res = 1.0;
        int k = n < 0 ? -n : n;
        for (int i = 0; i < k; ++i)
            res *= x;

        if (n < 0) return 1 / res;
        else return res;
    }
};
