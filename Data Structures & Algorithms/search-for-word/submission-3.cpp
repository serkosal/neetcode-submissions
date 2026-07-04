class Solution {
public:
    using Point = pair<int, int>;

struct Candidate {
    Point coord;
    set<Point> visited;

    Candidate(const Point& p) : coord(p)
    {}

    Candidate(const Point& p, const set<Point>& visited) 
    : coord(p), visited(visited) {}
};

bool exist(vector<vector<char>>& board, string word) {
    const int ROWS = board.size(), COLS = board[0].size(),
        w_len = word.size();
    
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            
            stack<Candidate> candidates; candidates.push({{r, c}});

            while (candidates.size()) {
                auto [coord, visited] = candidates.top(); candidates.pop();
                const int ch_index = visited.size();

                if (ch_index > w_len || ch_index < 0) continue;
                if (ch_index == w_len) return true;
                if (coord.first < 0 || coord.first >= ROWS) continue;
                if (coord.second < 0 || coord.second >= COLS) continue;
                if (board[coord.first][coord.second] != word[ch_index]) continue;
                if (visited.contains(coord)) continue;

                visited.insert(coord);

                for (const auto& p : array<Point, 4>{{
                    {coord.first + 1, coord.second},
                    {coord.first - 1, coord.second},
                    {coord.first, coord.second + 1},
                    {coord.first, coord.second - 1},
                }}) candidates.push({p, visited});
            }
        }
    }

    return false;
}
};
