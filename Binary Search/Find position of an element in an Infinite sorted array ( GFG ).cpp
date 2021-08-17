// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }

// ********************************************************************************************************


// C++ program to demonstrate working of an algorithm that finds an element in an array of infinite size
#include<bits/stdc++.h>
using namespace std;

// Simple Binary Search
int binarySearch(int a[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (a[mid] == x)
            return mid;

        if (a[mid] > x)
            r = mid - 1;

        else
            l =  mid + 1;
    }

    return -1;
}

// Function takes an infinite size array and a key to be searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be infinite in this function.
int findPos(int a[], int target)
{
    int start = 0, end = 1;
    int val = a[0];

    // Find 'end' to do binary search
    while (val < target)
    {
        start = end;     // store previous high
        end = 2 * end;   // double high index
        val = a[end];    // update new val
    }

    // at this point we have found appropriate 'start' and 'end' indices, Thus, now we can use binary search
    return binarySearch(a, start, end, key);
}


int main()
{
    int a[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 10;

    int ans = findPos(a, target);

    if (ans == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;

}
