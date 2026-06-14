class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board);

    bool check_num(vector<bool>& nums, int n)
    {
        if (n >= 1 && n <= 9)
        {
            if  (nums[n-1]) return true;
            else nums[n-1] = true;
        }

        return false;
    }
};

bool Solution::isValidSudoku(vector<vector<char>>& board) 
{
    {
        vector<bool> founded_col(9);
        vector<bool> founded_row(9);
        for (int i = 0; i < 9; ++i)
        {
            fill_n(founded_col.begin(), 9, false);
            fill_n(founded_row.begin(), 9, false);
            for (int j = 0; j < 9; ++j)
            {
                if ( check_num(founded_col, board[i][j] - '0') ) 
                    return false;
                if ( check_num(founded_row, board[j][i] - '0') )
                    return false;
            }
        }
    }
    vector<bool> founded_sqr(9);
    for (int y = 0; y < 9; y += 3)
    {
        for (int x = 0; x < 9; x += 3)
        {
            fill_n(founded_sqr.begin(), 9, false);

            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (check_num(founded_sqr, board[y + i][x + j] - '0')) 
                        return false;
        }
    }
    return true;
}