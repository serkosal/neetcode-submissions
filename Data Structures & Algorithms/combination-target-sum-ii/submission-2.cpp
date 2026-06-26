class Solution {
    struct Candidate {
        multiset<int> vec;
        int sum = 0;

        Candidate(const multiset<int>& v = {}, int sum = 0) : vec(v), sum(sum)
        {}

        bool operator<(const Candidate& other) const {
            return vec < other.vec;
        }
    };

    
public:
    vector<vector<int>> combinationSum2(const vector<int>& candidates, int target) {
        set<multiset<int>> res;
        set<Candidate> q = {{}};
        for (int num : candidates) {
            set<Candidate> temp;
            for (const auto& t : q) {
                const int new_sum = t.sum + num;
                if (new_sum > target) continue;

                auto new_candidate = t;
                new_candidate.sum = new_sum;
                new_candidate.vec.insert(num);

                if (new_candidate.sum == target)
                    res.insert(new_candidate.vec);
                else
                    temp.insert(new_candidate);
            }
            q.merge(temp);
        }

        vector<vector<int>> res_vec = {};
        for (const auto& multis : res) {
            vector<int> temp;
            for (const auto& el : multis)
                temp.push_back(el);
            res_vec.push_back(temp);
        }

        return res_vec;
    }
};
