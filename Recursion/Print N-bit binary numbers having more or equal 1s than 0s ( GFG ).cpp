// Recursion -

// 3 Approaches towards Recursion
// a) Recusrive Tree ( using I/P O/P method )
// b) Base-Condition-Hypothesis-Induction ( making I/P smaller )
// c) Choice Diagram  ( DP )


// ************************************************************************************

// a) Recursive Tree ( using I/P O/P method ) is used here. ( Athough Hard problem of this )



class Solution {
public:

    vector<string> ans;

    void solve(int zero, int one, int n, string output) {

        // Base condition, when n becomes zero, then we get a N-bit binary string
        // ( leaf node of the recursive tree )
        if (n == 0) {
            ans.push_back(output);
            return;
        }

        // Choice of choosing 1 is always available
        string out1 = output;
        out1 += "1";

        solve(zero, one + 1, n - 1, out1);

        // Choice of choosing 0 is available only when 'zero' is less than 'one'
        if (zero < one) {
            string out2 = output;
            out2 += "0";

            solve(zero + 1, one, n - 1, out2);
        }
    }

    // Solution starts here
    vector<string> NBitBinary(int n)
    {
        // initialised output string
        string output = "";

        // variables to keep track of the number of 0 and 1 used
        int zero = 0;
        int one = 0;

        // recursive function for the recursive tree
        solve(zero, one, n, output);

        return ans;
    }
};
