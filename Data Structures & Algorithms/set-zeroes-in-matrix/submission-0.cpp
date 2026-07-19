class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        const int ROWS = m.size(), COLS = m[0].size();

        queue<pair<int, int>> zero_p;
        for (int r = 0; r < ROWS; ++r)
            for (int c = 0; c < COLS; ++c)
                if (m[r][c] == 0)
                    zero_p.push({r, c});

        while (zero_p.size()) {
            auto [row, col] = zero_p.front();

            m[row] = vector<int>(COLS, 0);
            for (int r = 0; r < ROWS; ++r) 
                m[r][col] = 0;

            zero_p.pop();
        }
    }
};
