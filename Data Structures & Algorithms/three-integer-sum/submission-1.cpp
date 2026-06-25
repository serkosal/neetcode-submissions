class Solution {
public:
    vector<vector<int>> threeSum(const vector<int>& nums) {
        vector<vector<int>> res = {};
        set<multiset<int>> res_set = {};
        unordered_map<int, vector<pair<int, int>>> hash;
        int sz = nums.size();
        for (int j = 0; j < sz; ++j) {
            for (int k = j + 1; k < sz; ++k)
                hash[-(nums[j] + nums[k])].push_back({j, k});
        }

        for (int i = 0; i < sz; ++i) {
            if (hash.contains(nums[i])) {
                for (const auto& [j, k] : hash[nums[i]])
                    if (i != j && i != k)
                        res_set.insert({nums[i], nums[j], nums[k]});
            }
        }

        for (const auto& s : res_set) {
            vector<int> temp;
            for (int num : s)
                temp.push_back(num);
            res.push_back(temp);
        }

        return res;
    }
};
