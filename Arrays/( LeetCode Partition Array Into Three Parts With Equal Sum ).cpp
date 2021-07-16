class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& a) {

        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);

        // if sum is not divisible by 3, then we can't divide array in 3 equal parts
        if ((sum % 3) != 0)
            return false;

        // Prefix sum array
        int pre[n];
        pre[0] = a[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + a[i];

        // Checking for the required value to be search i.e (total sum)/3
        int req = sum / 3;

        // to store the index at which we got the first (total sum)/3 ( or index upto which
        // we can partition first part )
        int ind = -1;

        for (int i = 0; i < n; i++)
        {
            if (pre[i] == req) {
                ind = i;
                break;
            }
        }

        // if not found such a point for partition of first part, then return false
        if (ind == -1)
            return false;

        // Now required value to be search becomes 2*(total sum / 3 )
        req += req;
        int ind2 = -1;

        for (int i = ind + 1; i < n; i++)
        {
            if (pre[i] == req) {
                ind2 = i;
                break;
            }
        }

        // if not found such a point for partition of second part
        // OR no more elements is present to make third partition, then return false
        if (ind2 == -1 or ind2 == n - 1)
            return false;

        return true;

    }
};
