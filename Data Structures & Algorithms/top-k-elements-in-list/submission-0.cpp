class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
    vector<int> res;
    //  num  count  
    map<int, int>   freq;  

    // O(n)
    for (const auto& num : nums )
    {
        if (freq.count(num)) 
            ++freq[num];
        else
            freq[num] = 1;
    }
    
    for (int i = 0; i < k; ++i)
    {
        auto it = max_element(freq.begin(), freq.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)
        {
            return p1.second < p2.second; 
        });

        res.insert(res.begin(), it->first);
        freq.erase(it->first);
    }

    return res; 
    }
};
