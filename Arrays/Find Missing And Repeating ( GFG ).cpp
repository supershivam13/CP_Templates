int ans[2];

class Solution {
public:
    int *findTwoElement(int *a, int n) {

        // Since the numbers are [1:N], so we use the array indices for storing the
        // visited state of each number, only the duplicate will be visited twice.
        // For each number we goto its index position and multiply by -1. In case
        // of duplicate it will be multiplied twice and the number will be +ve.

        for (int i = 0; i < n; i++) {
            int index = abs(a[i]) - 1;

            // mark as visited
            a[index] *= -1;

            // incase of duplicate, this will become +ve
            if (a[index] > 0) {
                ans[0] = abs(a[i]);
                break;
            }
        }
        // ans[0] now stores the repeating number


        int x = 0, y = 0;

        // x is the bitwise xor of all elements from 1 to N
        for (int i = 1; i <= n; i++)
            x ^= i;

        // y is the bitwise xor of all elements from 1 to N except the missing and repeating number
        for (int i = 0; i < n; i++)
            y ^= abs(a[i]);

        // ans[1] will have the bitwise xor of only missing and repeating number
        ans[1] = x ^ y;

        ans[1] ^= ans[0];

        return ans;

    }
};
