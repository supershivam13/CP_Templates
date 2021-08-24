// Recursion -

// 3 Approaches towards Recursion
// a) Recusrive Tree ( using I/P O/P method )
// b) Base-Condition-Hypothesis-Induction ( making I/P smaller )
// c) Choice Diagram  ( DP )


// ************************************************************************************

// a) Recursive Tree ( using I/P O/P method ) is used here.


class Solution {
public:
    vector<string> ans;

    void solve(string input, string out) {

        // Base condition, when input length is zero, then we get a subset
        // ( leaf node of the recursive tree )
        if (input.length() == 0) {
            ans.push_back(out);
            return;
        }

        // copying the previous output for two recursive call functions
        string out1 = out;
        string out2 = out;

        // in first recursive call, we decide to not print the space in output, so simply adding
        // the next character of the input to the output
        out1.push_back(input[0]);

        // in second recursive call, we decide to print the space in output, so adding " " before
        // adding the next character of the input to the output
        out2 += " ";
        out2.push_back(input[0]);

        // making the input smaller for next recursive calls
        input.erase(0, 1);

        // Making two recursive calls with smaller inputs
        solve(input, out1);
        solve(input, out2);

    }

    // Solution starts here
    vector<string> permutation(string S) {

        // we can't place space before first character of the input string
        string output = "";
        output += S[0];

        S.erase(0, 1);

        // now recursive function for the recursive tree
        solve(S, output);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
