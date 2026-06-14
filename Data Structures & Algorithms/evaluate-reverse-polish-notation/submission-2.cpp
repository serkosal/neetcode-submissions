class Solution {
public:
    bool is_num(const string& str)
    {
        if (str.size() == 0) return false;

        if (str[0] == '-' && str.size() >= 2)
        {
            for (int i = 1; i < str.size(); ++i)
                if (!isdigit(str[i])) return false;
        }
        else
        {
            for (char ch : str)
                if (!isdigit(ch)) return false;
        }

        return true;
    }

    int evalRPN(vector<string>& tokens) 
    {
        stack<int> integers;
        for (const auto& token : tokens)
        {
            if (is_num(token))
            {
                integers.push(atoi(token.c_str()));
            }
            else if (token.size() == 1)
            {
                char ch = token[0];
                int a, b;
                if (ch == '+')
                {
                    a = integers.top();
                    integers.pop();
                    b = integers.top();
                    integers.pop();
                    integers.push(a + b);
                }
                else if (ch == '-')
                {
                    a = integers.top();
                    integers.pop();
                    b = integers.top();
                    integers.pop();
                    integers.push(b - a);
                }
                else if (ch == '*')
                {
                    a = integers.top();
                    integers.pop();
                    b = integers.top();
                    integers.pop();
                    integers.push(a * b);
                }
                else if (ch == '/')
                {
                    a = integers.top();
                    integers.pop();
                    b = integers.top();
                    integers.pop();
                    integers.push(b / a);
                }
            }
        }

        return integers.top();    
    }
};
