class Solution {
public:
    int uniquePaths(const int ROWS, const int COLS) {
        vector board(ROWS, vector<int>(COLS));
        for (int c = 0; c < COLS; ++c) board[0][c] = 1;
        for (int r = 0; r < ROWS; ++r) board[r][0] = 1;
        for (int r = 1; r < ROWS; ++r)
            for (int c = 1; c < COLS; ++c)
                board[r][c] = board[r - 1][c] + board[r][c - 1];

        return board[ROWS - 1][COLS - 1];
    }
};
