// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// 1) When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.


// 2) Binary Search can also be applied when the answer space is monotonic. That is for a point A in the answer
// space, all values >= A or all values <= A satisfies the conditions and hence, we use Binary Search to find
// point A {which is the answer}. ( Example - Allocate Minimum Number of Pages{GFG}, Magnetic Force Between
// Two Balls{LeetCode}, Aggressive Cows{SPOJ} )

// *************************************************************************************************************

#include <bits/stdc++.h>
using namespace std;




// isvalid function returns true if it is possible to place c cows with minimum distance 'dist'
bool isvalid(vector<int>&a, int n, int c, int dist) {

    int count = 1;
    // variable to store the position of the last placed cow
    int last_place = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] - last_place >= dist) {
            count++;
            last_place = a[i];
        }
    }

    // if we are able to place c cows with minimum distance 'dist' in b/w them, then return true.
    if (count >= c)
        return true;
    else
        return false;
}

int AggresiveCows(vector<int>& a, int c) {

    int n = a.size();
    sort(a.begin(), a.end());
    int res = -1, mid;

    // position of stalls are not given distinct, so minimum distance between any two balls can be 0.
    int low = 0;
    // maximum distance between two cows = distance between first and last stall
    int high = a[n - 1] - a[0];

    while (low <= high) {
        mid = low + ((high - low) / 2);

        // isvalid function returns true if it is possible to place c cows with minimum distance 'mid'
        // if true, store the result and move to right part as we want to maximise this 'mid'
        if (isvalid(a, n, c, mid) == true) {
            res = mid;
            low = mid + 1;
        }
        // else move to the left part as we need to reduce the distance between the cows
        else
            high = mid - 1;
    }
    return res;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, c;
        cin >> n >> c;
        vector<int> a(n, 0);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << AggresiveCows(a, c) << endl;
    }

}
