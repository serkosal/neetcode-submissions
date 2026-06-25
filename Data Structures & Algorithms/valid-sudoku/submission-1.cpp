class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < 9; ++i) {
            unordered_map<char, int> rows_check;
            unordered_map<char, int> cols_check;
            unordered_map<char, int> quad_check;

            const int sx = i % 3 * 3, sy = i / 3 * 3;
            for (int j = 0; j < 9; ++j) {
                char ch;
                // rows
                ch = board[i][j];
                if (ch != '.' && ++rows_check[ch] > 1)
                    return false;

                // cols
                ch = board[j][i];
                if (ch != '.' && ++cols_check[ch] > 1)
                    return false;

                // quad
                ch = board[sy + j / 3][sx + j % 3];
                if (ch != '.' && ++quad_check[ch] > 1)
                    return false;
            }
        }

        return true;
    }
};
