class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        vector<int> res = {}; res.reserve(k);

        // O(n)
        map<int, int> freq;
        for (int num: nums) 
            ++freq[num];

        // O(n)
        vector<vector<int>> buckets(nums.size());
        for (auto [num, fr]: freq)
            buckets[fr-1].push_back(num);

        // O(k)
        for (
            auto [it, i] = tuple(buckets.rbegin(), 0); 
            it != buckets.rend(); 
            ++it
        ) for (int num : *it) {
            res.push_back(num);
            if (++i >= k) return res;
        }

        return res;
    }
};
