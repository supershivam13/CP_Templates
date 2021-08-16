// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// *******************************************************************************************************
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {

        int mid = l + (r - l) / 2;

        // If the element is present at
        // one of the middle 3 positions
        if (arr[mid] == x)
            return mid;
        if (mid > l && arr[mid - 1] == x)
            return (mid - 1);
        if (mid < r && arr[mid + 1] == x)
            return (mid + 1);

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            r = mid - 2;

        // Else the element can only be present
        // in right subarray
        else
            l = mid + 2;
    }

    // We reach here when element is not present in array
    return -1;
}


int main()
{
    int arr[] = {3, 2, 10, 4, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;

    return 0;
}
