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

    // recursive function to generate all balanced paranthesis with given open and close brackets
    void balParanthesis(int open, int close, string output) {

        // Base condition, when both open and close are zero, then we get a balanced Paranthesis string
        // ( leaf node of the recursive tree )
        if (open == 0 and close == 0) {
            ans.push_back(output);
            return;
        }

        // Choice of open bracket is always available as long as 'open' > 0
        if (open > 0) {
            string out1 = output;
            out1 += "(";
            balParanthesis(open - 1, close, out1);
        }

        // Choice of close bracket is only available when more number of open brackets are used than close
        // brackets in order to have a balanced Paranthesis {i.e 'open' < 'close' }
        if (open < close) {
            string out2 = output;
            out2 += ")";
            balParanthesis(open, close - 1, out2);
        }

    }

    // Solution starts here
    vector<string> generateParenthesis(int n) {

        // Initially, we have 'n' open and 'n' close brackets
        int open = n;
        int close = n;

        // initialised output string
        string output = "";

        // recursive function tog
        balParanthesis(open, close, output);

        return ans;
    }
};
