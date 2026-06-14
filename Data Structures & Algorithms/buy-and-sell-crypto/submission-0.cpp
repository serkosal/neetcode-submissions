class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        int max_delta = 0;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j <= n - i; ++j)
            {
                int max_ind = j, min_ind = j;
                for (int k = 0; k < i; ++k)
                {
                    if (prices[j + k] > prices[max_ind])
                        max_ind = j + k;

                    if (prices[j + k] < prices[min_ind])
                        min_ind = j + k;
                    
                    if (prices[max_ind] - prices[min_ind] > max_delta && min_ind < max_ind)
                        max_delta = prices[max_ind] - prices[min_ind];
                            
                }
            }
        }

        return max_delta;
    }
};
