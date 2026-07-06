class Solution {
public:
    unordered_map<int, int> hash = {{0, 1}, {1, 1}};

    int climbStairs(int n) {
        if (!hash.contains(n)) 
            hash[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return hash[n];
    }
};
