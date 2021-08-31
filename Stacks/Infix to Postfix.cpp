// Algorithm -

// 1. Scan the infix expression from left to right.
// 2. If the scanned character is an operand, output it.
// 3. If the scanned character is an ‘(‘, push it to the stack.
// 4. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered,
//    and discard both the parenthesis.
// 5. Else,
//       1 If the precedence of the scanned operator is greater than the precedence of the operator
//         in the stack or the stack is empty or the stack contains a ‘(‘ ), push it.
//       2 Else, Pop all the operators from the stack which are greater than or equal to in precedence
//         than that of the scanned operator. After doing that Push the scanned operator to the stack.
// 6. Repeat steps 2-6 until infix expression is scanned.
// 7. Now, after the For loop, Pop and output from the stack until it is not empty.
// 8. Print the output.


class Solution {
public:

    //Function to return precedence of operators
    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    // Solution starts here
    string infixToPostfix(string s)
    {
        int n = s.length();
        string result;
        stack<char> st;


        for (int i = 0; i < n; i++) {
            char c = s[i];

            // if 'c' is alphabet or number, append to the result string
            if (isalnum(c))
                result += c;

            else if (c == '(')
                st.push(c);

            // if 'c' is closing bracket, then append all the elements present in stack to the result string
            // till we don't find a open bracket
            else if (c == ')') {

                while (st.top() != '(') {
                    result += st.top();
                    st.pop();
                }

                // pop the '(' opening bracket from the stack
                st.pop();
            }

            // if 'c' is an operator
            else {

                // append all the element present in stack to the result until precedence of stack.top()
                // become less than that of incoming operator 'c'
                // This loop won't run if the prec(c) is already greater than prec(s.top())
                while (st.size() > 0 and prec(c) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }

                // push the operator 'c' into the stack
                st.push(c);
            }

        }

        while (st.size()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
