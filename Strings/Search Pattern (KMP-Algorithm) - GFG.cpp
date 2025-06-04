// KMP ALGORITHM
// TIME COMPLEXITY - O( N+M )
// SPACE COMPLEXITY - O(M)

class Solution {
  public:
    void computeLPS(string& pattern, vector<int>& lps) {
        int len = 0;  // length of the previous longest prefix suffix
        lps[0] = 0;   // lps[0] is always 0

        int i = 1;
        while (i < pattern.length()) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0)
                    len = lps[len - 1];  // try shorter previous LPS
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // CODE starts here
    vector<int> search(string& pattern, string& text) {

        // string 's' = 'pattern' + "#" + 'text'
        string s = pattern + '#' + text;   // adding a character '#' in between which will never occur in both strings
        vector<int> ans;
        vector<int> lps(s.length(), 0);    // LPS array, initialised with zero
        computeLPS(s, lps);                // Function to calculate LPS Array (Longest Proper Prefix Function)
        
       
        // In the LPS array, the places where there LPS[i] == length of the pattern, it confirms that there is a occurence
        // of pattern at that place, and LPS[i] can never be greater than the length of pattern because we have added a
        // character ( # here ) which will never occur in the text string
        for(int i = 0; i<s.length(); i++)
            if (lps[i] == pattern.length())
                ans.push_back(i-(2*pattern.length()));    // storing the occurrences of 'pattern' in 's' string
        
        return ans;
    }
};
