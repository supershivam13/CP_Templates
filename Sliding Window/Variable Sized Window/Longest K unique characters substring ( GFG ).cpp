// VARIABLE SIZED SLIDING WINDOW

//  i = start of window
//  j = end of window
//  window size = j-i+1


class Solution {
public:
    int longestKSubstr(string s, int k) {

        // Checking if k is more than the no. of unique characters in string itself
        // if yes, then return -1 as no such substring is possible
        set<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
            st.insert(s[i]);

        // if yes, then return -1 as no such substring is possible
        if (k > st.size())
            return -1;


        // Variable Size Sliding Window starts here
        int i = 0, j = 0, ans = -1;

        // map to store the count of characters in the current window
        // and map.size() gives the number of unique characters
        unordered_map<char, int> mp;


        // j++ will always be there so can be written at the end of while loop as well
        // instead of writing j++ in the three different cases
        while (j < n) {

            mp[s[j]]++;

            // when there is less than k unique characters in the window, simply carry on
            if (mp.size() < k)
                j++;

            // when there is k unique characters in the window, then it can be a candidate
            // so updating the ans
            else if (mp.size() == k) {
                ans = max(ans, j - i + 1);
                j++;
            }

            // when there is more than k unique characters in the window, then start removing the
            // elements from the window
            else {

                while (mp.size() > k) {
                    mp[s[i]]--;

                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);

                    i++;
                }

                j++;
            }

        }

        return ans;
    }
};
