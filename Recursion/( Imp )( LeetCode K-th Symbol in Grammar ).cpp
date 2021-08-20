// Observations-
// 1) for any n-th row, first half of the row is same as (n-1)th row.
// 2) for any n-th row, second half of the row is complement of the (n-1)th row.


class Solution {
public:
    int kthGrammar(int n, int k) {

        // Base Condition (given in question)
        if (n == 1 and k == 1)
            return 0;

        // length of the n-th row  = 2^(n-1)
        int length = pow(2, n - 1);
        int mid = length / 2;

        // if k lies in the first half, then it is same as k-th term in (n-1)th row
        if (k <= mid)
            return kthGrammar(n - 1, k);
        // else k lies in the second half, then it is the complement of the k-th term in (n-1)th row
        else
            return 1 ^ (kthGrammar(n - 1, k - mid));

    }
};
