#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // BUBBLE SORT
    // For n elements, we need to do (n-1) iterations
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
