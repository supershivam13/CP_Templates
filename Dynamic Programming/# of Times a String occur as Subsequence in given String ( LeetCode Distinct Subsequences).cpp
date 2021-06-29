// Find number of times a string 't' occurs as a subsequence in given string 's'

// A Dynamic Programming based C++ program to find the
// number of times the second string occurs in the first
// string, whether continuous or discontinuous

#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)

// DP Array
unsigned long long dp[1001][1001];


// Iterative DP function to find the number of times
// the second string occurs in the first string,
// whether continuous or discontinuous
class Solution {
public:
    int numDistinct(string s, string t) {

        int m = s.length();
        int n = t.length();

        // Base Condition
        fo(i, 0, m) {
            fo(j, 0, n) {

                // If first string is empty, then there is 0 way
                if (i == 0)
                    dp[i][j] = 0;

                // If second string is empty, then only one way to make it ( as empty string )
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        fo(i, 1, m) {
            fo(j, 1, n) {

                // If last characters are same, we have two options -
                // 1. consider last characters of both strings in solution
                // 2. ignore last character of first string
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

                // else last characters are different, ignore last character of first string
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};
