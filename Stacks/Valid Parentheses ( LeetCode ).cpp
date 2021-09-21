class Solution {
public:
    bool isValid(string x) {

        stack<char> s;
        int n = x.size();

        for (int i = 0; i < n; i++) {

            if (x[i] == '(' or x[i] == '{' or x[i] == '[')
                s.push(x[i]);

            else if (x[i] == ')') {
                if (s.empty() or s.top() != '(')
                    return false;
                else
                    s.pop();
            }
            else if (x[i] == '}') {
                if (s.empty() or s.top() != '{')
                    return false;
                else
                    s.pop();
            }
            else if (x[i] == ']') {
                if (s.empty() or s.top() != '[')
                    return false;
                else
                    s.pop();
            }
        }

        if (s.size() == 0)
            return true;
        else
            return false;
    }
};
