class Solution {
public:

vector<int> spiralOrder(const vector<vector<int>> &m)
{
    vector<int> res;
    int ROWS = m.size(), COLS = m[0].size(), N = ROWS * COLS;

    for (int d = 0, n = 0; n < N; ++d)
    {
        int r = d, c = d;
        while (true) {
            res.push_back(m[r][c]); ++n;
            if (n >= N) return res;
            if (c + 1 == COLS - d) break;
            ++c; 
        }

        ++r;
        while (true) {
            res.push_back(m[r][c]); ++n;
            if (n >= N) return res;
            if (r + 1 == ROWS - d) break;
            ++r; 
        }

        --c;
        while (true) {
            res.push_back(m[r][c]); ++n;
            if (n >= N) return res;
            if (c - 1 < d) break;
            --c; 
        }
        
        --r;
        while (true) {
            res.push_back(m[r][c]); ++n;
            if (n >= N) return res;
            if (r - 1 <= d) break;
            --r; 
        }
    }

    return res;
}
};
