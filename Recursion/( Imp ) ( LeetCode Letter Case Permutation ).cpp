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

    void solve(string input, string output) {

        // Base condition, when input length is zero, then we get a subset
        // ( leaf node of the recursive tree )
        if (input.length() == 0) {
            ans.push_back(output);
            return;
        }

        int d = input[0];

        // if the first input character is integer, then simply add it in output and continue with one
        // recursive call on smaller input
        if (d <= 57) {

            output.push_back(input[0]);
            input.erase(0, 1);

            solve(input, output);
        }
        // else first input character is a lowercase or uppercase alphabet
        else {

            // copying the previous output for two recursive call functions
            string out1 = output;
            string out2 = output;

            // in first recursive call, we decide to not change the case of the character, so simply adding
            // the character of the input to the output
            out1.push_back(input[0]);

            // in second recursive call, we decide to change the case of the character, so adding the
            // complementary case character of the input to the output
            int comp = d >= 97 ? input[0] - 32 : input[0] + 32;
            char c = comp;
            out2.push_back(c);

            // making the input smaller for next recursive calls
            input.erase(0, 1);

            // Making two recursive calls with smaller inputs
            solve(input, out1);
            solve(input, out2);

        }
    }

    // Solution starts here
    vector<string> letterCasePermutation(string S) {

        // initialised output string
        string output = "";

        // now recursive function for the recursive tree
        solve(S, output);

        return ans;
    }
};
