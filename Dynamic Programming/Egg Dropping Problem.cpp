#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solveEggDrop(int n, int f) {

    // if there are only one or zero floors
    if (f == 1 || f == 0)
        return f;

    // if there is only one egg, then start by dropping from the last floor, will need
    // minimum k (k = number of floors) trials in worst case
    if (n == 1)
        return f;

    // MEMOIZATION
    if (dp[n][f] != -1)
        return dp[n][f];

    int min = INT_MAX, res;

    // Checking for all the possibilities by dropping egg from each floor
    for (int k = 1; k <= f; k++) {
        // max because we have to take the worst case scenario of (egg break,egg not break)
        res = 1 + max(solveEggDrop(n - 1, k - 1), solveEggDrop(n, f - k));

        if (res < min)
            min = res;
    }

    // stroring the result in the dp matrix
    return dp[n][f] = min;
}

int main() {

    // n = number of eggs, f = number of floors
    int n, f;
    cin >> n >> f;
    memset(dp, -1, sizeof(dp));
    cout << solveEggDrop(n, f);
}

