#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // INSERTION SORT { Insert an element from an unsorted array to its correct position in sorted array }

    // For n elements, we need to do (n-1) iterations
    // but starting from index 1(or second element) in INSERTION SORT
    for (int i = 1; i < n; i++) {

        int current = a[i];
        int j = i - 1;
        while (a[j] > current and j >= 0 ) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
