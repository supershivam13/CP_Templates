class Solution {
public:
    bool isValid(string x) {

        stack<char> s;
        int n = x.size();

        for (int i = 0; i < n; i++) {

            if (x[i] == '(' or x[i] == '{' or x[i] == '[') // any open bracket, push into stack
                s.push(x[i]);

            else if (x[i] == ')') {        // check if matching open bracket is at top
                if (s.empty() or s.top() != '(')
                    return false;
                else
                    s.pop();
            }
            else if (x[i] == '}') {         // check if matching open bracket is at top
                if (s.empty() or s.top() != '{')
                    return false;
                else
                    s.pop();
            }
            else if (x[i] == ']') {         // check if matching open bracket is at top
                if (s.empty() or s.top() != '[')
                    return false;
                else
                    s.pop();
            }
        }

        if (s.size() == 0)    // if stack is empty, only then parantheses are valid
            return true;
        else
            return false;
    }
};
