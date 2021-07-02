#include <bits/stdc++.h>
using namespace std;

bool isScramble(string S1, string S2)
{
    // Strings of non-equal length cant' be scramble strings
    if (S1.length() != S2.length())
        return false;

    int n = S1.length();

    // Empty strings are scramble strings
    if (n == 0)
        return true;

    // Equal strings are scramble strings
    if (S1 == S2)
        return true;

    // Check for the condition of anagram (i.e contains the same characters in same numbers OR
    // one string can be formed from the other using the characters of second string only )
    string copy_S1 = S1, copy_S2 = S2;

    sort(copy_S1.begin(), copy_S1.end());
    sort(copy_S2.begin(), copy_S2.end());

    if (copy_S1 != copy_S2)
        return false;


    for (int i = 1; i < n; i++) {

        // CASE I - SWAPPING IS NOT DONE
        // Check if S2[0...i] is a scrambled string of S1[0...i] and if S2[i+1...n]
        // is a scrambled string of S1[i+1...n]
        if (isScramble(S1.substr(0, i), S2.substr(0, i)) and isScramble(S1.substr(i, n - i), S2.substr(i, n - i)))
            return true;


        // CASE II - SWAPPING IS DONE
        // Check if S2[0...i] is a scrambled string of S1[n-i...n] and S2[i+1...n]
        // is a scramble string of S1[0...n-i-1]
        if (isScramble(S1.substr(0, i), S2.substr(n - i, i)) and isScramble(S1.substr(i, n - i), S2.substr(0, n - i)))
            return true;

    }

    // If none of the above conditions are satisfied
    return false;
}

// Driver Code
int main()
{
    string S1 = "coder";
    string S2 = "ocred";

    if (isScramble(S1, S2)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}
