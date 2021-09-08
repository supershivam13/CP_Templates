// QUICK SORT

// Time Complexity - O(N^2) { Best - O( N* logN ) }
// Space Complexity - O( logN ) { to store the recursive calls in stack }
// Stability - Unstable ( Only Quick, Selection, Heap are unstable, rest all are stable )

#include <bits/stdc++.h>
using namespace std;

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    // swap takes two pointer addresses to swap the values stored at those addresses
    // so can't do like swap(arr[i+1],pivot) WRONG
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QUICK SORT
void quickSort(int arr[], int low, int high)
{   
    // Base Condition -> 1 or 0 or -1 elements
    if(low>=high)
        return;
        
    // pi is partitioning index, arr[pi] is now at right place
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    // Printing the sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
