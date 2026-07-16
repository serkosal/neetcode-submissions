class Solution {
public:
    unordered_map<string_view, int> memo;
    int numDecodings(string_view s) {
        if (s.size() == 0) return 1;
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;

        if (memo.contains(s)) return memo[s];

        int res = 0, num;
        auto [ptr, ec] = std::from_chars(s.data(), s.data() + 2, num);
        if (ec == std::errc()) {
            if (num <= 26)
                res = numDecodings({s.begin() + 2, s.end()});
        }
        else throw "An error occured lol.\n";
        
        res += numDecodings({s.begin(), s.begin() + 1}) * numDecodings({s.begin() + 1, s.end()});
        memo[s] = res;
        return res;
    }

};
