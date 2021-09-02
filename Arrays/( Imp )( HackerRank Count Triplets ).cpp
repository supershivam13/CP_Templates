// Brute force -
// Generate all the (i,j,k) pairs using 3 nested for loops
// Time Complexity  O(N^3)


// SLIDING HASHING TECHNIQUE

// Time Complexity - O(N)

#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
    int n, r, x, ans = 0;
    cin >> n >> r;

    map<int, int> left;
    map<int, int> right;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);

        // Initially left map subarray will be empy and right subarray will have all stored in it
        left[x] = 0;
        right[x]++;
    }


    // Sliding a window of size 1 (v[i] only) and accordingly updating the left and right map
    // assuming a=v[i] is middle term, then looking for (a/r) in left map and (a*r) in right map
    for (int i = 0; i < n; i++) {

        right[v[i]]--;

        // first term (a/r) should be a whole number
        if (v[i] % r == 0) {

            int a = v[i] / r;
            int b = v[i];
            int c = v[i] * r;

            ans += (left[a] * right[c]);
        }

        left[v[i]]++;
    }

    cout << ans << endl;
}
