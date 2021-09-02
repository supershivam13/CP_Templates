// Time Complexity - O( N^2 * logN ) { logN is used in insertion in Map }


#include <bits/stdc++.h>
using namespace std;

// Returns count of total number of anagram
// substrings of string str
int countOfAnagramSubstring(string str)
{
    int N = str.length();

    // To store counts of substrings with given set of frequencies.
    // ( Frequency vector will act as key here )
    map<vector<int>, int> mp;


    // Getting all substrings of the string, and generating frequency vector for each substring
    // and storing the count of such frequency vector in map
    for (int i = 0; i < N; i++)
    {
        vector<int> freq(26, 0);

        for (int j = i; j < N; j++)
        {
            // update freq vector of current substring
            freq[str[j] - 'a']++;

            // increase count corresponding to this frequency vector
            // ( Frequency vector is acting as key here )
            mp[freq]++;
        }
    }

    int result = 0;

    // loop over all different freq array and
    // aggregate substring count
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int freq = it->second;

        // nC2 ways to select any two
        result += ((freq) * (freq - 1)) / 2;
    }

    return result;
}



int main()
{
    string str = "xyyx";
    cout << countOfAnagramSubstring(str) << endl;
}
