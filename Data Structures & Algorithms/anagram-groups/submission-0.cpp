class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        vector<vector<string>> res = {};

        unordered_map<string, vector<string>> groups;

        for (const auto& str : strs) {

            string sorted = str;
            std::sort(sorted.begin(), sorted.end());

            groups[sorted].push_back(str);
        }

        for (const auto& [_, group] : groups)
            res.push_back(group);

        return res;
    }

};
