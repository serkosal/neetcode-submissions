class Solution {
public:
    vector<int> dailyTemperatures(const vector<int> &temps){
        vector<int> res(temps.size(), 0);

        int pos = temps.size() - 1, r_max = temps.back();
        while (pos > 0) {
            r_max = std::max(r_max, temps[pos]);
            if (temps[pos - 1] < temps[pos--]) break;
        }

        for (stack<pair<int, int>> st; pos >= 0; --pos) {

            int cur_temp = temps[pos], cur_days = 1;
            if (cur_temp >= r_max) {
                r_max = std::max(r_max, cur_temp);
                st = {};
                continue;
            }

            while (!st.empty()) {
                auto [temp, days] = st.top();
                if (cur_temp < temp) 
                    break;

                cur_days += days;

                st.pop();
            }

            st.push({cur_temp, cur_days});
            res[pos] = cur_days;
        }

        return res;
    }
};
