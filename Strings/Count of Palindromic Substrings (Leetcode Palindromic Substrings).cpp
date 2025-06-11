// TC - O(N^2)
// SC - O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;              // stores the count of palindromic substrings

        // For a string of length n, there are 2n-1 possible centers:
        // n single characters (odd-length palindromes)
        // n-1 pairs between characters (even-length palindromes)
        for (int center = 0; center < 2 * n - 1; center++) {    // Expand around each possible center
            int left = center / 2;
            int right = left + center % 2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};
