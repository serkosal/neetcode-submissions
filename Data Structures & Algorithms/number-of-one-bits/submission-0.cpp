class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        while (n) {
            if (n % 2) ++i;
            n /= 2;
        }

        return i;
    }
};
