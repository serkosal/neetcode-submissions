class Solution {
public:

    int min_replacements(const string& s)
    {
        int max = 0;
        map<char, int> freq;

        for (char ch : s)
            if (++freq[ch] > max)
                max = freq[ch];

        return s.size() - max;
    }

    int characterReplacement(string s, int k) 
    {
        int n = s.size(), res = 0;

        int w = n;
        while (w > 0 && w >= k)
        {
            for (int j = 0; j <= n - w; ++j)
            {
                int cur_repl = min_replacements(s.substr(j, w));
                if (cur_repl <= k && w > res) res = w;
            }

            if (res) return res;

            --w;
        }

        return res;
    }
};
