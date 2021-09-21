// Longest Valid Parenthesis

// Brute Force - O(N^3)


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int ans = 0;

        // stack to store indices of '('
        stack<int> st;

        // '-1' marks the starting of a valid substring
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            // if opening bracket, then push it's index
            if (s[i] == '(')
                st.push(i);
            else
            {
                // pop previous '(' index
                if (!st.empty())
                    st.pop();

                // length of longest valid substring till now
                if (!st.empty())
                    ans = max(ans, i - st.top());
                else
                    // marks the beginning of next valid substring
                    st.push(i);
            }
        }

        return ans;
    }
};
