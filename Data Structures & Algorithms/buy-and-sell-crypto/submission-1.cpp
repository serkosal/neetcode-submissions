class Solution {
public:

    int maxProfit(const vector<int>& p) {
        if (p.size() == 0) return 0;

        int max_profit = 0, b = 0, s = 0;
        for (int i = 0; i < p.size(); ++i) {

            if (p[i] > p[s]) s = i;
            if (p[i] < p[b]) {
                b = i;
                s = i;
            }

            int cur_profit = p[s] - p[b];
            if (b < s && cur_profit > max_profit)
                max_profit = cur_profit;
        }
        
        return max_profit;
    }
};
