#include <bits/stdc++.h>
using namespace std;

// 3D DP Matrix ( as 3 parameters are changing in the function calls )
int dp[101][101][2];

// isTrue is the bool for which we want to calculate the number of ways
int parenthesis_count(string s, int i, int j, int isTrue)
{
    // Base Condition ( empty string )
    if (i > j)
        return false;

    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    // Memoization
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;

    // k+=2 so that k comes only on the operators, not on the 'T' or 'F'
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        // leftT = Count no. of ways of T in left partition
        // leftF = Count no. of ways of F in left partition
        // rightT = Count no. of ways of T in right partition
        // rightF = Count no. of ways of F in right partition
        int leftF, leftT, rightT, rightF;

        if (dp[i][k - 1][1] == -1)
            leftT = parenthesis_count(s, i, k - 1, 1);
        else
            leftT = dp[i][k - 1][1];


        if (dp[k + 1][j][1] == -1)
            rightT = parenthesis_count(s, k + 1, j, 1);
        else
            rightT = dp[k + 1][j][1];


        if (dp[i][k - 1][0] == -1)
            leftF = parenthesis_count(s, i, k - 1, 0);
        else
            leftF = dp[i][k - 1][0];


        if (dp[k + 1][j][0] == -1)
            rightF = parenthesis_count(s, k + 1, j, 0);
        else
            rightF = dp[k + 1][j][0];


        // if the operator between the left and right partition is '&',
        // then both partition should be true for True value
        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF
                       + leftF * rightT;
        }
        // if the operator between the left and right partition is '|',
        // then either or both partition can be true for True value
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF
                       + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        // if the operator between the left and right partition is '^',
        // then one partition should be true and other should be false for True value
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }

        dp[i][j][isTrue] = ans;
    }

    return ans;
}

// Driver Code
int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    // Now, we obtained the string T|T&F^T
    int n = s.length();

    // There are 4 ways for the above example in which expression can be evaluated to True
    // ((T|T)&(F^T))
    // (T|(T&(F^T)))
    // (((T|T)&F)^T)
    // (T|((T&F)^T))

    memset(dp, -1, sizeof(dp));

    cout << parenthesis_count(s, 0, n - 1, 1);
    return 0;
}
