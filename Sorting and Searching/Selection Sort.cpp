// SELECTION SORT

// Time Complexity - O ( N^2 )
// Space Complexity - O(1)
// Stability - Unstable ( Only Quick, Selection, Heap are unstable, rest all are stable )


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // SELECTION SORT { Select the minimum element from the unsorted array and keep swapping it with the first
    // element of the unsorted array }

    // For n elements, we need to do (n-1) iterations
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already sorted
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
                swap(a[i], a[j]);
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
