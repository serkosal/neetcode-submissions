class Solution {
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> res = {{}};

        for (int num : nums) {
            vector<vector<int>> new_res = res;
            for (vector<int>& cur : new_res)
                cur.push_back(num);
            for (const vector<int>& cur : new_res)
                res.push_back(cur);
        }

        return res;
    }
};
