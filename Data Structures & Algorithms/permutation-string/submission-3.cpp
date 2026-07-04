class Solution {
public:
    bool checkInclusion(const string& needle, const string& hay) {
        unordered_map<char, int> needle_map;
        for (char ch : needle) ++needle_map[ch];

        const int needle_sz = needle.size(), hay_sz = hay.size();
        
        unordered_map<char, int> hay_map;
        for (int i = 0; i < needle_sz; ++i) ++hay_map[hay[i]];

        for (
            auto l = hay.begin(), r = l + needle_sz - 1; 
            r < hay.end();
        ) {
            if (hay_map == needle_map) return true;

            if (--hay_map[*l] == 0) hay_map.erase(*l);
            ++l;
            ++r;
            ++hay_map[*r];
        }

        return false;
    }
};
