class Solution {
public:
    struct Parenthesis{
        string str;
        int opened;
        int closed;

        Parenthesis()
        {
            str = "(";
            opened = 1;
            closed = 0;
        }

        Parenthesis open_new()
        {
            return Parenthesis(str + "(", opened + 1, closed);
        }

        Parenthesis close()
        {
            return Parenthesis(str + ")", opened, closed + 1);
        }

        Parenthesis(string str, int opened, int closed) 
            : str(str), opened(opened), closed(closed) {}
    };

    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;

        // строка кол-во скобок
        stack<Parenthesis> st; st.push({});
        
        while (st.size())
        {
            auto top = st.top();
            st.pop();

            
            if (top.closed != n)
            {
                if (top.opened - top.closed) st.push(top.close());
                if (top.opened < n) st.push(top.open_new());
            }
            else
                res.push_back(top.str);
        }

        return res;
    }
};
