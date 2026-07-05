class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.size() == 1) return strs[0]; 
        
        for (int i = 0; true; ++i) {
            for (int j = 1; j < strs.size(); ++j ) {
                if (i >= strs[j].size()) return res;
                if (strs[j - 1][i] != strs[j][i]) return res;
            }

            res += strs[0][i];
        }

        return res;
    }
};