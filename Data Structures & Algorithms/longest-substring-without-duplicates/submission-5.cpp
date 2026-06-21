class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
    const int sz = s.size();
    if (!sz) return 0;
    int longest = 1;

    // char -> previous_pos
    unordered_map<char, int> h; h[s[0]] = 0;
    for (
        int l = 0, r = 1;
        l < sz - longest && r < sz;
    ) { 
        for (;
            r < sz && !h.contains(s[r]); 
            ++r
        ) h[s[r]] = r;

        longest = std::max(int(h.size()), longest);

        if (r == sz) break;

        const int prev_pos = h[s[r]];
        while (l < prev_pos)
            h.erase(s[l++]);
        h[s[l++]] = r++;
    }

    return longest;
}

};
