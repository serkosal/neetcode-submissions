class Solution {
public:
    const string OPS = "+-*/";

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (const string& token: tokens) {
            if (OPS.contains(token) && nums.size() > 1) {
                int n2 = nums.top(); nums.pop();
                int n1 = nums.top(); nums.pop();
                int res;
                if (token == "+") res = n1 + n2;
                else if (token == "-") res = n1 - n2;
                else if (token == "*") res = n1 * n2;
                else if (token == "/") res = n1 / n2;
                nums.push(res);
            }
            else nums.push(stoi(token));
        }

        return nums.top();
    }
};
