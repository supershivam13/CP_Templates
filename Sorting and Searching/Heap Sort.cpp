// HEAP SORT

// Time Complexity - O (N * logN)
// Space Complexity - O(1)
// Stability - Unstable ( Only Quick, Selection, Heap are unstable, rest all are stable )

#include <bits/stdc++.h>
using namespace std;


// To heapify a subtree rooted with node i which is
// an index in a[]. n is size of heap
void heapify(int a[], int n, int i)
{
    int largest = i;        // Initialize largest as root
    int l = 2 * i + 1;      // left = 2*i + 1    ( 0-based indexing )
    int r = 2 * i + 2;      // right = 2*i + 2   ( 0-based indexing )

    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than 'largest' so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root, then swap and heapify the affected subtree
    if (largest != i) {
        swap(a[i], a[largest]);

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}


// HEAP SORT
void heapSort(int a[], int n)
{
    // Build heap for all nodes i which has childrens (rearrange array)
    // ( No use of calling heapify to leaf nodes i.e nodes i which has no child )
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(a[0], a[i]);

        // call heapify on the reduced heap
        // now size of the heap is i and it is rooted at 0
        heapify(a, i, 0);
    }
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // name of an array is a pointer pointing to the first element of the array, So when we pass array in
    // other function, it is always passed by reference.
    // Since array is always passed by reference in C++, so changes made in the array in other functions
    // will also reflect here.
    heapSort(a, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

}
