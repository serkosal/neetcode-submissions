class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && l < s.size())
        {
            if (s[l] >= 'A' && s[l] <= 'Z') s[l] += 32;
            if (s[r] >= 'A' && s[r] <= 'Z') s[r] += 32;

            if ( !( s[l] >= '0' && s[l] <= '9' || s[l] >= 'a' && s[l] <= 'z' ) )
            {
                ++l;
                continue;
            }
            if ( !( s[r] >= '0' && s[r] <= '9' || s[r] >= 'a' && s[r] <= 'z' ) )
            {
                --r;
                continue;
            }

            if (s[l] != s[r]) return false;

            ++l;
            --r;
        }

        return true;
    }
};
