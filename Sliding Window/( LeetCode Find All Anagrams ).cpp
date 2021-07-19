class Solution {
public:
    vector<int> findAnagrams(string s, string pat) {

        // map of all character occurences of the pat string, i.e char and its count.
        unordered_map<char, int> m;
        for (auto it : pat) m[it]++;

        // variable 'count' denotes the distinct characters left in a sliding window.
        int count = m.size();

        // k = window size
        int k = pat.length();
        int n = s.length();
        vector<int> ans;


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

                // If the count is 0, it means all the characters needed for its anagram is here in it,
                // therefore increase your answer
                if (count == 0)
                    ans.push_back(i);
            }

            // for subsequent windows of size k ( except the first window )
            else {

                // Remember i is already incremented by the for loop

                // processing the newly added element in the window
                if (m.find(s[i + k - 1]) != m.end()) {
                    m[s[i + k - 1]]--;

                    // if changes from 1->0, then it indicates that character is present in required quantity
                    if (m[s[i + k - 1]] == 0)
                        count--;
                }

                // processing the recently removed element from the window
                if (m.find(s[i - 1]) != m.end()) {
                    m[s[i - 1]]++;

                    // if changes from 0->1
                    if (m[s[i - 1]] == 1)
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
