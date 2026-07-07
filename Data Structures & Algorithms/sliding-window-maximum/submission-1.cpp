class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> res = {};

        map<int, int> hash;
        auto l = nums.begin(), r = l;
        for (auto e = nums.begin() + k; r < e && r < nums.end(); ++r)
            ++hash[*r];

        --r;
        
        while (hash.size()) {
            res.push_back((*hash.rbegin()).first);

            if(--hash[*l] <= 0) hash.erase(*l);
            ++l; ++r;
            if (r >= nums.end()) break;
            ++hash[*r];
        }

        return res;
    }
};
