class Solution {
public:
    using PalindromeHash = unordered_map<string_view, bool>;

    bool isPalindrome(string_view s, PalindromeHash& hash) {
        if (s.size() <= 1) return true;
        const bool firstLastEq = s.front() == s.back();
        if (s.size() == 2) return firstLastEq;
        if (!firstLastEq) return false;

        const string_view inner{s.begin() + 1, s.end() - 1};
        if (hash.contains(inner)) return hash[inner];

        return hash[inner] = isPalindrome(inner, hash);
    }

    int countSubstrings(string_view s) {
        PalindromeHash hash;
        int res = s.size();

        for (int w = 2; w <= s.size(); ++w)
            for (auto start = s.begin(); start <= s.end() - w; ++start)
                if (isPalindrome({start, start + w}, hash)) ++res;

        return res;
    }

};
