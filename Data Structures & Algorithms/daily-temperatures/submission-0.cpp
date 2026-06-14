class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps)
    {
        int n = temps.size();
        stack<int> st;
        vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; --i)
        {
            auto temp = st;
            int init_size = temp.size();
            while (temp.size())
            {
                if (temp.top() > temps[i])
                {
                    res[i] = init_size - temp.size() + 1;
                    break;
                }


                temp.pop();
            }

            st.push(temps[i]);
        }

        return res;
    }
};
