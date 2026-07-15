struct Point {
    int y{0}, x{0};

    bool operator==(const Point& p) const = default;
};
namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point& p) const noexcept {
            size_t h1 = std::hash<int>{}(p.x);
            size_t h2 = std::hash<int>{}(p.y);

            return h1 ^ (h2 << 1);
        }
    };
}

class Solution {
    int ROWS{0}, COLS{0};
public:
    void BFT(
        const vector<vector<int>>& heights, 
        unordered_set<Point>& visited
    ) {
        const int ROWS = heights.size(), COLS = heights[0].size();

        queue<Point> q; 
        for (const auto& p : visited) q.push(p);

        while (q.size()) {
            auto [y, x] = q.front(); q.pop();
            for (const auto& p_new : vector<Point>{
                {y + 1, x}, {y, x + 1},
                {y - 1, x}, {y, x - 1},
            }) if (!visited.contains(p_new)
                && 0 <= p_new.y && p_new.y < ROWS
                && 0 <= p_new.x && p_new.x < COLS
                && heights[p_new.y][p_new.x] >= heights[y][x]) {
                    q.push(p_new);
                    visited.insert(p_new);
                }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<Point> pacific;
        unordered_set<Point> atlantic;
        const int ROWS = heights.size(), COLS = heights[0].size();
        for (int y = 0; y < ROWS; ++y) {
            pacific.insert({y, 0});
            atlantic.insert({y, COLS - 1});
        }
        for (int x = 0; x < COLS; ++x) {
            pacific.insert({0, x});
            atlantic.insert({ROWS - 1, x});
        }
        BFT(heights, pacific);
        BFT(heights, atlantic);

        vector<vector<int>> res;
        for (const auto& p : atlantic)
            if (pacific.contains(p))
                res.push_back({p.y, p.x});
        
        return res;
    }
};
