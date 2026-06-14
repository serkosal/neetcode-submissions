class Solution {
public:
    bool is_reapiting(const string& s)
    {
        map<char, bool> chrs;

        for (const char& ch : s)
        {
            if (chrs.count(ch)) return true;
            else chrs[ch] = true;
        }

        return false;
    }

    int lengthOfLongestSubstring(string s) 
    {
        int max_l = 0, n = s.size();

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= n - i; ++j)
                if (!is_reapiting(s.substr(j, i)) && i > max_l)
                    max_l = i;

        return max_l;
    }
};
