class Solution {
    using PalindromeHash = unordered_map<string, bool>;

    bool isPalindrome(string_view s, PalindromeHash& hash) {
        if (s.size() <= 1) return true;
        const bool firstLastEq = s.front() == s.back();
        if (s.size() == 2) return firstLastEq;
        if (!firstLastEq) return false;

        const string inner{s.begin() + 1, s.end() - 1};
        if (hash.contains(inner)) return hash[inner];

        return hash[inner] = isPalindrome(inner, hash);
    }
public:

string longestPalindrome(string_view s) {
        PalindromeHash hash;

        for (int w = s.size(); w > 0; --w) {
            for (auto start = s.begin(); start <= s.end() - w; ++start) {
                const string_view cur {start, start + w};
                if (isPalindrome(cur, hash)) return string(cur);
            }
        }

        return "";
    }
};
