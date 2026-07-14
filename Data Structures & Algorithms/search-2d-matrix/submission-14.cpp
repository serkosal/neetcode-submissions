class Solution {
public:
    int find_row(vector<vector<int>>& mat, int target) {
        int l = 0, r = mat.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (mat[m][0] == target) return m;
            else if (mat[m][0] < target) l = m + 1;
            else r = m - 1;
        }
        if (mat[l][0] <= target)
            return l;
        else return l - 1;
    }

    int find_col(vector<int>& row, int target) {
        int l = 0, r = row.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (row[m] == target) return m;
            else if (row[m] < target) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = find_row(matrix, target);
        if (row == -1) return false;

        int col = find_col(matrix[row], target);
        return col != -1;
    }
};
