class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
    set<vector<int>> res;

    for (auto it1 = nums.begin(); it1 != nums.end(); ++it1)
        for (auto it2 = std::next(it1); it2 != nums.end(); ++it2)
            for (auto it3 = std::next(it2); it3 != nums.end(); ++it3)
                if (*it1 + *it2 + *it3 == 0)
                {
                    vector<int> temp = {*it1, *it2, *it3};
                    std::sort(temp.begin(), temp.end());
                    res.insert(temp);
                }


    vector<vector<int>> ress; ress.reserve(res.size());
    for (auto& vec : res)
        ress.push_back(vec);

    return ress;
    }
};
