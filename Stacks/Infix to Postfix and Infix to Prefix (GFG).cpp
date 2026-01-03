// INFIX TO POSTFIX ( More Important than Infix to Prefix )

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
    string infixToPostfix(string s) {
        int n = s.length();
        string result;
        stack<char> st;

        unordered_map<char, int> precedence = { {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1} };

        for (int i = 0; i < n; i++) {
            char c = s[i];

            // Operand
            if (isalnum(c))
                result += c;
            // Opening bracket
            else if (c == '(')
                st.push(c);
            // Closing bracket
            else if (c == ')') {
                // append all the elements present in stack to the result string
                // till we don't find a open bracket
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();   // remove '('
            }
            // Operator
            else {
                // Pop operators from stack while they have higher precedence,
                // or same precedence with left associativity (except '^' which is right-associative)
                while (!st.empty() && st.top() != '(' &&
                       (precedence[c] < precedence[st.top()] ||
                        (precedence[c] == precedence[st.top()] && c != '^'))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};


// *******************************************************************************




// INFIX TO PREFIX

// Same as Infix to Postfix, only Two steps needed to be done before.

// Steps -

// 1. Reverse the string.
// 2. Change all open brackets to close and vice versa.

// After this, it is same as Infix to Postfix conversion
