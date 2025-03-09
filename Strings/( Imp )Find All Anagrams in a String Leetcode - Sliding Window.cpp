class Solution {
public:
    vector<int> findAnagrams(string s, string pat) {

        vector<int> ans;  // to store results
        int n = s.length();

        unordered_map<char, int> m;  // { char: frequency }
        for (auto it : pat) 
            m[it]++;

        // variable 'count' denotes the distinct characters in a sliding window.
        int count = m.size();   // can't use map.size() as we need to know the chacters present in 'pattern' string

        int k = pat.length();   // k = window size

        // Pre-processing of first window of size K
        for (int i = 0; i < k; i++) {

            if (m.find(s[i]) != m.end()) {
                m[s[i]]--;

                // when the no. of occurence of a character becomes zero, so number of distinct
                // characters also decrease by 1
                if (m[s[i]] == 0)
                    count--;
            }
        }

        // SLIDING WINDOW TECHNIQUE
        for (int i = 0; i <= n - k; i++) {

            // case of first window of size K
            if (i == 0) {

                if (count == 0)         // If the count is 0, it means all the characters needed for its anagram is here in it,
                    ans.push_back(i);  // therefore adding it to answer
            }

            // for subsequent windows of size K ( except the first window )
            else {

                // Remember i is already incremented by the for loop

                if (m.find(s[i + k - 1]) != m.end()) {  // processing the newly added element in the window
                    m[s[i + k - 1]]--;

                    // if changes from 1->0, then it indicates that character is present in required quantity
                    if (m[s[i + k - 1]] == 0)
                        count--;
                }

                if (m.find(s[i - 1]) != m.end()) {  // processing the recently removed element from the windoW
                    m[s[i - 1]]++;

                    if (m[s[i - 1]] == 1)   // if changes from 0->1, then increase count
                        count++;
                }

                // NOW PRE-PROCESSING IS DONE, CALCULATING THE ANS FROM THE WINDOW
                if (count == 0)
                    ans.push_back(i);
            }
        }

        return ans;
    }
};
