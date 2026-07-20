class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        const int SIZE = m.size();
        for (int r = 0; r < SIZE / 2; ++r)
                swap(m[r], m[SIZE - 1 - r]);

        for (int r = 0; r < SIZE; ++r)
            for (int c = r + 1; c < SIZE; ++c)
                swap(m[r][c], m[c][r]);
    }
};
