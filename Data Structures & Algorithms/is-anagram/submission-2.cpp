class Solution {
public:

    /* multiset solution
    bool isAnagram(string s, string t) 
    {
        multiset<char> st1;
        for (const char& ch : s) st1.insert(ch);

        multiset<char> st2;
        for (const char& ch : t) st2.insert(ch);

        return st1 == st2;
    }*/

    // map solution
    bool isAnagram(string s, string t) 
    {
        map<char, int> mp1;
        for (const char& ch : s)
        {
            if (mp1.count(ch)) 
                ++mp1[ch];
            else
                mp1[ch] = 0;
        } 

        map<char, int> mp2;
        for (const char& ch : t)
        {
            if (mp2.count(ch)) 
                ++mp2[ch];
            else
                mp2[ch] = 0;
        } 

        return mp1 == mp2;
    }
};
