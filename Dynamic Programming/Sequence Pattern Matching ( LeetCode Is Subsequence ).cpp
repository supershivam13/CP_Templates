#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)

int dp[1001][10001];

// To check whether string x is a subsequence of string y or not.

// Return true if LCS string of x and y is equal to the string x
// else return false

class Solution {
public:
    int isSubsequence(string x, string y) {
        int m = x.length();
        int n = y.length();

        // Initialisation ( Base condition )
        fo(i, 0, m) {
            fo(j, 0, n) {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }

        fo(i, 1, m) {
            fo(j, 1, n) {
                // if character of both strings matches
                if (x[i - 1] == y[j - 1] )
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        // Now for Getting the LCS String, traceback the dp matrix
        string lcs = "";
        int a = m, b = n;

        // keep running the loop until we reach the first row or first column of the dp matrix
        while (a > 0 and b > 0) {

            // if characters are equal, then move diagonally left-up, and put that character in the LCS string
            if (x[a - 1] == y[b - 1]) {
                lcs.push_back(x[a - 1]);
                a--, b--;
            }
            // else move in the direction of max ( up, left ) in the dp matrix
            else {
                if (dp[a - 1][b] > dp[a][b - 1])
                    a--;
                else
                    b--;
            }
        }

        // the obtained LCS till now is reverse as what is needed, so reversing it again to get the correct LCS
        reverse(lcs.begin(), lcs.end());

        // Return true if LCS string of x and y is equal to the string x
        if (x == lcs) {
            return true;
        }
        else
            return false;
    }
};
