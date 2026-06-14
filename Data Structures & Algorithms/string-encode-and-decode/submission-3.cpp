class Solution {
public:

    const char SEPARATOR_CHAR = ':', SHIELDING_CHAR = '#';

    string encode(vector<string>& strs)
    {
        string res = "";

        for (const string& str : strs)
        {
            res += ":";

            for (char ch : str)
            {
                if (ch == SEPARATOR_CHAR) 
                    res += string(1, SHIELDING_CHAR) + string(1, SEPARATOR_CHAR);
                else if (ch == SHIELDING_CHAR) 
                    res += string(2, SHIELDING_CHAR);
                else res += ch;
            }
        }

        return res;
    }

    vector<string> decode(string s) 
    {
        vector<string> res;

        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == SEPARATOR_CHAR)
                res.push_back("");
            else if (s[i] == SHIELDING_CHAR && i + 1 < n && (s[i + 1] == SHIELDING_CHAR || s[i + 1] == SEPARATOR_CHAR))
                res.back() += s[++i];
            else
                res.back() += s[i];
        }

        return res;
    }
};
