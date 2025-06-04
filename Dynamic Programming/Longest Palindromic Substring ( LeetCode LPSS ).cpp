// NOTE : We can't use the same way as we used in LPS ( longest palindrome subsequence )
// ( i.e LPSS != LCSS(string a, reverse of string a) )

// Solving this Question without DP ( not based on LCS Pattern )

// Time Complexity - O(N^2)
// Space Complexity - O(1)

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.length() <= 1)
            return s;

        int max_len = 1;    // each character of a string can be treated as a palindrome of length 1
        int n = s.length();

        int st = 0, end = 0;  // to store the start and end index of the longest palindromic substring

        // CHECKING FOR THE PLAINDROMES OF ODD LENGTH
        // In case of odd-length palindromes,each character of the string can act as the centre of the palindrome,
        // So looping over all the characters of the string
        for (int i = 0; i < n; i++) {

            int l = i, r = i;   // taking ith index as the centre of the palindrome

            while (l >= 0 && r < n) {
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }

            int len = r - l - 1;
            if (len > max_len) {
                max_len = len;
                st = l + 1;     // adding and subtracting 1 to 'l' and 'r' respectively,
                end = r - 1;    // because 'r' must have gone one index forward and 'l' one step backward in while loop
            }
        }

        // CHECKING FOR THE PLAINDROMES OF EVEN LENGTH
        // In case of even-length palindromes, the middle space between any two characters of the string can
        // act as the centre of the palindrome, So looping over all such middle spaces characters of the string
        for (int i = 0; i < n - 1; ++i) {

            // the middle space between the ith and (i+1)th character acting as the centre of the palindrome
            int l = i, r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }
            
            int len = r - l - 1;
            if (len > max_len) {
                max_len = len;
                st = l + 1;     // adding and subtracting 1 to 'l' and 'r' respectively,
                end = r - 1;    // because 'r' must have gone one index forward and 'l' one step backward in while loop
            }
        }

        // LPSS is at the index 'st' of length 'max_len'
        return s.substr(st, max_len);
    }
};
