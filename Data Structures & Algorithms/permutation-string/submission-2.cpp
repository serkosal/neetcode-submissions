class Solution {
public:
    bool is_permutation(const string& s1, const string& s2)
    {
        multiset<char> st1, st2;
        for (char ch : s1) st1.insert(ch);
        for (char ch : s2) st2.insert(ch);

        return st1 == st2;
    }

    bool checkInclusion(string s1, string s2) 
    {
        int w = s1.size(), n = s2.size();
        for (int j = 0; j <= n - w; ++j)
            if (is_permutation(s2.substr(j, w), s1))
                return true;

        return false;    
    }
};
