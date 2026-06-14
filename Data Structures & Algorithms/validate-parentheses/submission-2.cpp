class Solution {
public:
    const string OPENINGS = "([{";
    const string CLOSINGS = ")]}";
    const unordered_map<char, char> BRACKETS_MAP = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    bool isValid(const string& s) {
        stack<char> openings;
    
        for (char ch : s) {
            if (OPENINGS.contains(ch)) 
                openings.push(ch);
            
            if (CLOSINGS.contains(ch)) {
                if (openings.empty() 
                || openings.top() != BRACKETS_MAP.at(ch)
                )   return false;
                
                openings.pop();
            }
        }

        return openings.empty();
        }
};
