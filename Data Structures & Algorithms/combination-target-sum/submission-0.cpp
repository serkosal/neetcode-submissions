class Solution {
    struct Candidate {
        vector<int> vec = {};
        int start = 0;
        int sum = 0;
    };
public:


    vector<vector<int>> combinationSum(const vector<int>& nums, int target) {
        if (nums.size() == 0) return {};
        
        vector<vector<int>> res;
        stack<Candidate> candidates; candidates.push({});

        while (!candidates.empty()) {
            auto c = candidates.top(); 
            candidates.pop();

            for (int i = nums.size() - 1; i >= c.start; --i) {
                Candidate c_new(c.vec, i, c.sum + nums[i]);
                c_new.vec.push_back(nums[i]);
                if (c_new.sum == target) res.push_back(c_new.vec);
                if (c_new.sum < target) candidates.push(c_new);
            }
        }

        return res;
    }
};
