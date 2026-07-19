class Solution {
public:
    int lengthOfLastWord(const string& s) {
        int res = 0;
        const int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            int t = 0;
            while (i + t < sz && s[i + t] != ' ')
                ++t;
            i += t;
            
            if (t) res = t;
        }

        return res;
    }
};