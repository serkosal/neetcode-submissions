class Solution {
public:
    bool isAnagram(string s, string t) {
    multiset<char> st1;
    for (const char& ch : s) st1.insert(ch);

    multiset<char> st2;
    for (const char& ch : t) st2.insert(ch);

    return st1 == st2;
    }
};
