// NOTE : We can't use the same way as we used in LPS ( longest palindrome subsequence )
// ( i.e LPSS != LCSS(string a, reverse of string a) )

// Solving this Question without DP ( not based on LCS Pattern )


// TC - O(N^2)
// SC - O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int count = 0;      // stores the count of palindromic substrings
        int max_len = 1;    // each character of a string can be treated as a palindrome of length 1
        int start = 0;      // index to store the start index of the longetst palindromic substring

        // For a string of length n, there are 2n-1 possible centers:
        // n single characters (odd-length palindromes)
        // n-1 pairs between characters (even-length palindromes)
        for (int center = 0; center < 2 * n - 1; center++) {    // Expand around each possible center
            int left = center / 2;
            int right = left + center % 2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;

                if(right-left+1>max_len){
                    max_len = right-left+1;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start,max_len);
    }
};
