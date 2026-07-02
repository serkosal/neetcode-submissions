class Solution {
public:
    int characterReplacement(const string& s, int k) {
        int res = 0;

        for (int sz = s.size(), w_sz = sz; w_sz > 0; --w_sz) {
            for (int start = 0; start <= sz - w_sz; ++start) {
                map<char, int> freqs;
                int most_freq = 0;

                for (int cur = start; cur < start + w_sz; ++cur)
                    most_freq = max(most_freq, ++freqs[s[cur]]);

                res = max(res, most_freq);
                
                if (w_sz - most_freq <= k) 
                    return w_sz; 
            }
        }

        return res;
    }
};
