// MERGE SORT

// Time Complexity - O ( N*logN )
// Space Complexity - O( N )
// Stability - Stable ( Only Quick, Selection, Heap are unstable, rest all are stable )


#include <bits/stdc++.h>
using namespace std;

// Merges two parts of array[] - [s,mid], [mid+1,end]
void merge(int a[], int left, int mid, int right)
{
    // size of left subarray
    int size1 = mid - left + 1;
    
    // size of left subarray
    int size2 = right - mid;
    
    // Temporary Array
    int temp[size1 + size2];

    int first = left;       // Initial index of first sub-array
    int second = mid + 1;   // Initial index of second sub-array
    int ind = 0;            // Initial index of merged array


    while (first <= mid  && second <= right) {

        if (a[first] <= a[second])
            temp[ind++] = a[first++];
        else
            temp[ind++] = a[second++];
    }

    // Copy the remaining elements of left[], if there are any
    while (first <= mid)
        temp[ind++] = a[first++];

    // Copy the remaining elements of right[], if there are any
    while (second <= right )
        temp[ind++] = a[second++];

    // Now, finally copying all the elements from temp to the original array
    for (int i = left; i <= right; i++)
        a[i] = temp[i-left];
}

// s = start is for left index and e = end is right index of the sub-array of arr to be sorted
void mergeSort(int a[], int s, int e)
{
    // Base Condition -> 1 or 0 or -1 elements
    if (s >= e)
        return;

    // 3 Steps -
    // 1. Divide     2. Sort       3. Merge

    int mid = s + (e - s) / 2;

    // Recursively call mergesort on two parts - [s,mid], [mid+1,end]
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    // Merge the two parts
    merge(a, s, mid, e);
}


int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}




