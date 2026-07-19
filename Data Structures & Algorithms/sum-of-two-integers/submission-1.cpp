class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            uint32_t carry = a & b; // Find where carries occur
            a = a ^ b;              // Add without carrying
            b = carry << 1;         // Shift carries to the next left column
        }
        return a;
    }
};
