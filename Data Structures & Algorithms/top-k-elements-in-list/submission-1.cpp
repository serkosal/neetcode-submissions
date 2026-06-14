class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        vector<int> res = {}; res.reserve(k);
        map<int, set<int>, std::greater<int>> nums_by_freq;

        map<int, int> num_to_freq;
        for (int num: nums) {
            int freq = ++num_to_freq[num];
            if (freq > 1)
                nums_by_freq[freq - 1].erase(num);
            nums_by_freq[freq].insert(num);
        }

        int i = 0;
        for (const auto& [freq, s] : nums_by_freq) {
            for (auto num: s ) {
                res.push_back(num);
                if (++i >= k) return res;
            }
        }

        return res;
    }
};
