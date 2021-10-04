class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {

        vector<vector<int>> ans;

        // n stores the size of the actual given vector
        int n = a.size();
        int i = 0, j;

        // inserting a {INT_MAX,INT_MAX} vector for ease
        vector<int> last(2, INT_MAX);
        a.push_back(last);
        sort(a.begin(), a.end());

        // since a.size() is increased by 1 after inserting, so can access upto index n
        while (i + 1 <= n) {

            // simply inserting all the non-overlapping intervals
            while (i + 1 <= n and a[i][1] < a[i + 1][0]) {
                ans.push_back(a[i]);
                i++;
            }

            // case of merging of two or more intervals
            while (i + 1 <= n and a[i][1] >= a[i + 1][0]) {

                j = i + 1;

                // determining the lower and upper bound of the final merged interval
                while (j<n and a[i][1] >= a[j][0]) {
                    a[i][0] = min(a[i][0], a[j][0]);
                    a[i][1] = max(a[i][1], a[j][1]);
                    j++;
                }

                ans.push_back(a[i]);
                i = j;
            }
        }

        return ans;
    }
};
