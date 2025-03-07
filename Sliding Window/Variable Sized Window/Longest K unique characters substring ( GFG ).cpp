// VARIABLE SIZED SLIDING WINDOW

//  i = start of window
//  j = end of window
//  window size = j-i+1


class Solution {
public:
    int longestKSubstr(string s, int k) {

        int n = s.length();
        set<char> st;

        for (auto c : s)
            st.insert(c);

        // Checking if k is more than the no. of unique characters in string itself
        // if yes, then return -1 as no such substring is possible
        if (k > st.size())
            return -1;

        // VARIABLE SIZED SLIDING WINDOW starts here
        int i = 0, j = 0, ans = -1;

        // map to store the count of characters in the current window
        // and map.size() gives the number of unique characters
        unordered_map<char, int> mp;

        while (j < n) {

            mp[s[j]]++;                    // adding calculations of j

            // when there is less than k unique characters in the window, do nothing
            if (mp.size() < k){}

            // when there is k unique characters in the window, then it can be a candidate, so updating the ans
            else if (mp.size() == k)             // if condition is met
                ans = max(ans, j - i + 1);

            // when there is more than k unique characters in the window, then start removing the
            // elements from the window
            else {

                while (mp.size() > k) {            // removing calculations of i
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
