class Solution {
public:
    bool isPalindrome(const string& s) {
        for  (
            auto l = s.begin(), r = s.end() - 1; 
            l < r;
            ++l, --r
        ) {
            while (l < s.end()   && !isalnum(*l)) ++l;
            while (r > s.begin() && !isalnum(*r) ) --r;
            if (l >= r) return true;
            if (tolower(*l) != tolower(*r)) return false;
        }

        return true;
    }
};
