class Solution {
    using Point = pair<int, int>;
    using PointHash = decltype([](const Point& p) {
        return std::hash<int>{}(p.first)
             ^ (std::hash<int>{}(p.second) << 1);
    });
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        const int ROWS = grid.size(), COLS = grid[0].size();
        unordered_set<Point, PointHash> visited;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                int count = 0;
                for (
                    auto to_visit = queue{deque{pair<int, int>{r, c}}};
                    to_visit.size();
                ) {
                    auto [y, x] = to_visit.front(); to_visit.pop();

                    if (visited.contains({y, x})) continue;
                    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) continue;
                    if (grid[y][x] == 0) continue;

                    visited.insert({y, x}); ++count;
                    to_visit.push({y + 1, x});
                    to_visit.push({y - 1, x});
                    to_visit.push({y, x + 1});
                    to_visit.push({y, x - 1});
                }
                res = max(res, count);
            }
        }

        return res;
    }
};
