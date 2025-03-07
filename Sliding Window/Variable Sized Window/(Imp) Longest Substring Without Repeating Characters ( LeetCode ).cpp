// VARIABLE SIZED SLIDING WINDOW

//  i = start of window
//  j = end of window
//  window size = j-i+1


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length(), i = 0, j = 0, ans = 0;

        // map to store the count of characters in the current window
        // and map.size() gives the number of unique characters
        unordered_map<char, int> mp;

        while (j < n) {
            
            mp[s[j]]++;                // adding calculations of j

            // this if statement will never will be executed
            // as it never will be true
            if (mp.size() > j - i + 1) {}
               
            // when there is all unique characters in the window, then window size = map.size()
            // so, it can be a potential candidate for ans
            else if (mp.size() == j - i + 1)            // condition is met
                ans = max(ans, j - i + 1);
                
            // when there is some repeating characters in the window, so removing elements till the
            // window size = map.size()
            else {
                while (mp.size() < j - i + 1) {        // removing calculations of i
                    mp[s[i]]--;

                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);

                    i++;
                }
            }
            
            j++;
        }
        return ans;
    }
};
