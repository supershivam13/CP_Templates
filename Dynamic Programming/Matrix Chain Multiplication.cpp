// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

// DP Array
int dp[1001][1001];

// Function for matrix chain multiplication
int matrixChainMemoised(int arr[], int i, int j)
{   
    // Base condition ( even array of one element (when i==j) is invalid so return 0 )
    if (i >= j)
        return 0;

    // Memoization
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    // Checking for the all possible partitions by partitioning from (i,k) and (k+1,j)
    for (int k = i; k < j; k++) {

        // Calculating the temporary ans
        int temp =  matrixChainMemoised(arr, i, k) + matrixChainMemoised(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

        ans = min(ans, temp);
    }

    // storing in the dp array and returning ans
    return dp[i][j] = ans;
}

int main()
{
    // n = number of intergers in array ( n - 1 matrix )
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Initialising Dp array with -1
    memset(dp, -1, sizeof(dp));

    // Calling function with values 1 and n-1 because 0 is not a valid input for i ( So, start with i=1 and j=n-1 )
    cout << "Minimum cost/number of multiplications is " << matrixChainMemoised(arr, 1, n - 1);
}
