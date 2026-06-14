class Solution {
public:

    bool isValid(string s) {
        stack<char> st;

        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if (ch == ')' || ch == ']' || ch == '}')
            {
                if (st.size() == 0) return false;
                else if (st.top() != '(' && ch == ')') return false;
                else if (st.top() != '[' && ch == ']') return false;
                else if (st.top() != '{' && ch == '}') return false;
                else st.pop();
            }
        }

        if (st.size()) return false;
            
        return true;
        
    }
};
