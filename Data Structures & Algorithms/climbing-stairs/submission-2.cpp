class Solution {
public:
    unordered_map<int, int> hash;

    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;

        if (!hash.contains(n)) 
            hash[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return hash[n];
    }
};
