class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size(), cols = matrix[0].size();

        int l_row = 0, r_row = rows - 1, l_col, r_col;
            
        while (l_row <= r_row && r_row < rows)
        {
            int cur, cur_row, cur_col;

            cur_row = l_row + (r_row - l_row) / 2;

            l_col = 0;
            r_col = cols - 1;
            while (l_col <= r_col && r_col < cols)
            {
                cur_col = l_col + (r_col - l_col) / 2;

                cur = matrix[cur_row][cur_col];

                if (cur == target) return true;
                else if (cur < target) l_col = cur_col + 1;
                else r_col = cur_col - 1;
            }

            if (cur < target) l_row = cur_row + 1;
            else r_row = cur_row - 1;
        }

        return false; 
    }
};
