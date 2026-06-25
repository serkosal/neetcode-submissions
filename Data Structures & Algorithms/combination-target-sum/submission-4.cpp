class Solution {
public:
    void solve(
        int i, 
        vector<vector<int>>&ans, vector<int>&a, 
        int sum, const vector<int>&c, int target
    ) {
        if (sum == target) ans.push_back(a);
        if (sum > target) return;

        for (int j = i; j < c.size(); j++) {
            a.push_back(c[j]);
            solve(j, ans, a, sum+c[j], c, target);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum(const vector<int>& c, int target) {
        vector<vector<int>> res;
        vector<int> a;
        solve(0, res, a, 0, c, target);
        return res;
    }
};