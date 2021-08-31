// Evaluation of PostFix Expression ( More Important than Prefix )

class Solution {
public:
    int evaluatePostfix(string s)
    {
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++) {

            char c = s[i];

            // if 'c' is an operator, then pop two elements from the stack
            // perform operation and push the result back into the stack
            if (c == '*' or c == '/' or c == '+' or c == '-') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                // always do ( B operator A ), never do ( A operator B )
                if (c == '*')
                    st.push(b * a);
                else if (c == '/')
                    st.push(b / a);
                else if (c == '+')
                    st.push(b + a);
                else
                    st.push(b - a);

            }
            else
                st.push(c - '0');

        }

        return st.top();
    }
};



// *******************************************************************************

// Almost same as PostFix Evaluation. Only two minor changes are -

// 1) Traverse Expression from Right to Left in Prefix.
// 2) Do ( A operator B ) in Prefix. { do (B operator A) in case of postfix }

class Solution {
public:
    int evaluatePrefix(string s)
    {
        int n = s.length();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            char c = s[i];

            // if 'c' is an operator, then pop two elements from the stack
            // perform operation and push the result back into the stack
            if (c == '*' or c == '/' or c == '+' or c == '-') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                // always do ( A operator B ) in case of prefix { do (B operator A) in case of postfix }
                if (c == '*')
                    st.push(a * b);
                else if (c == '/')
                    st.push(a / b);
                else if (c == '+')
                    st.push(a + b);
                else
                    st.push(a - b);

            }
            else
                st.push(c - '0');

        }

        return st.top();
    }
};
