// Recursion -

// 3 Approaches towards Recursion
// a) Recusrive Tree ( using I/P O/P method )
// b) Base-Condition-Hypothesis-Induction ( making I/P smaller )
// c) Choice Diagram  ( DP )


// ************************************************************************************

// a) Recursive Tree ( using I/P O/P method ) is used here.

class Solution {
public:
    vector<vector<int>> ans;

    // Recursive function to generate all subsets of a vector { PowerSet }
    void subsets(vector<int> a, vector<int>out) {

        // Base condition, when input length is zero, then we get a subset ( leaf node of the recursive tree )
        if (a.size() == 0) {
            ans.push_back(out);
            return;
        }

        vector<int> out1 = out;   // copying the previous output for two recursive call functions
        vector<int> out2 = out;   // copying the previous output for two recursive call functions

        // in first recursive call, we decide to not take the input in output, so no change in output
        // in second recursive call, we decide to take the input in output, so adding the first element of input
        out2.push_back(a[0]);

        // making the input smaller for next recursive calls
        a.erase(a.begin());

        // Making two recursive calls with smaller inputs
        subsets(a, out1);
        subsets(a, out2);
    }

    // Solution starts here
    vector<vector<int>> subsets(vector<int>& a) {

        vector<int> out;  // initialised output vector
        subsets(a, out);  // recursive function to generate all subsets of a vector { PowerSet }

        return ans;
    }
};
