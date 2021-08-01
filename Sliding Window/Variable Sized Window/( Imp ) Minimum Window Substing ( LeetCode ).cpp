// VARIABLE SIZED SLIDING WINDOW

//  i = start of window
//  j = end of window
//  window size = j-i+1


class Solution {
public:
    string minWindow(string s, string p) {

        int n = s.length();
        int n1 = p.length();

        // if pattern.length() > text.length(), then no substring possible
        if (n1 > n)
            return "";

        // Variable Sized Sliding Window starts here

        // map to store the characters and their occurences of the pattern string
        unordered_map<char, int> mp;
        for (int i = 0; i < n1; i++)
            mp[p[i]]++;

        // count indicates the number of charaters needed to get a potential candidate
        int count = mp.size();
        int i = 0, j = 0, ans = INT_MAX, ind = INT_MAX;

        while (j < n) {

            // if character is found in map, then decrementing the occurence in the map 'mp'
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;

                // if occurence of that character becomes zero, then decrement the count
                // count indicates the number of charaters needed to get a potential candidate
                if (mp[s[j]] == 0)
                    count--;
            }

            if (count > 0)
                j++;

            // if count == 0, then we get a potential candidate
            else if (count == 0) {

                if (ans > j - i + 1) {
                    ans = j - i + 1;
                    ind = i;
                }

                // removing the elements from the window to minimize the result
                while (count == 0) {
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;

                        if (mp[s[i]] == 1) {

                            count++;

                            if (ans > j - i + 1) {
                                ans = j - i + 1;
                                ind = i;
                            }
                        }

                        i++;
                    }
                    // if not found in the map, then simply remove the character from the window
                    else
                        i++;
                }

                j++;
            }
        }

        // If no such substring is possible
        if (ans == INT_MAX)
            return "";

        // string generation from index 'ind' of length 'ans' from string s
        string res = "";
        for (int i = ind; ans > 0; i++) {
            res += s[i];
            ans--;
        }

        return res;
    }
};
