// NOTE : We can't use the same way as we used in LPS ( longest palindrome subsequence )
// ( i.e LPSS != LCSS(string a, reverse of string a) )

// Solving this Question without DP ( not based on LCS Pattern )

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.length() <= 1)
            return s;

        // each character of a string can be treated as a palindrome of length 1
        int max_len = 1;

        int n = s.length();

        // to store the start and end index of the longest palindromic substring
        int st = 0, end = 0;

        // CHECKING FOR THE PLAINDROMES OF ODD LENGTH
        // In case of odd-length palindromes,each character of the string can act as the centre of the palindrome,
        // So looping over all the characters of the string
        for (int i = 0; i < n; i++) {

            // taking ith index as the centre of the palindrome
            int l = i, r = i;

            while (l >= 0 && r < n) {
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }

            int len = r - l - 1;
            if (len > max_len) {
                max_len = len;

                // adding and subtracting 1 to 'l' and 'r' respectively,
                // because 'r' must have gone one index forward and 'l' one step backward in the while loop
                st = l + 1;
                end = r - 1;
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

                // adding and subtracting 1 to 'l' and 'r' respectively,
                // because 'r' must have gone one index forward and 'l' one step backward in the while loop
                st = l + 1;
                end = r - 1;
            }
        }

        // LPSS is at the index 'st' of length 'max_len'
        return s.substr(st, max_len);

    }
};
