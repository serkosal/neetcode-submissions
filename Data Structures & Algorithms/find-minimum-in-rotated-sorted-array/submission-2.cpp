class Solution {
public:
    int findMin(const vector<int> &nums) {
        
        int m = std::numeric_limits<int>::max();
        for (int num : nums)
            if (num < m) 
                m = num;

        return m;
    }
};
