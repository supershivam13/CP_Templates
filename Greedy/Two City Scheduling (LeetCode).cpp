// GREEDY SOLUTION

// Time complexcity -  O(N log N)
// Space Complexcity - O ( N )

class Solution {
public:

    // Costs of '2n' people is given
    int twoCitySchedCost(vector<vector<int>>& costs) {

        int ans = 0;
        vector<int>refund;

        // First assume we are sending every person to first city
        // and what refund we will get if send a person to second city instead of first
        for (auto it : costs) {
            ans += it[0];
            refund.push_back(it[0] - it[1]);
        }

        // Sorting in decreasing order on the basis of refunds
        sort(refund.begin(), refund.end(), greater<int>());

        // now sending n peoples to second city and removing the refund we added in the cost
        for (int i = 0; i < (refund.size() / 2); i++)
            ans -= refund[i];

        return ans;
    }
};
