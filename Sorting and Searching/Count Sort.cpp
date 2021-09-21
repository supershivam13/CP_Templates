// COUNT SORT

// Time Compplexity - O( max( max_ele,N ) )
// Space Complexity - O( max( max_ele,N ) )
// Stability - Stable

// Properties -

// 1)  It is not a comparison based sorting. It running time complexity is O(n)
//     with space proportional to the range of data.

// 2) Counting sort can be extended to work for negative inputs also.So what we do is, we find
//    the minimum element and we will store count of that minimum element at zero index,
//    and size of the count array will be = (max_ele - min_ele + 1)


// *************************************************************

#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, max_ele = INT_MIN;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    max_ele = max(max_ele, a[i]);
  }

  // Make a count array of size {max_element present in array} + 1
  int count[max_ele + 1];
  memset(count, 0, sizeof(count));

  // Storing the count of each distinct element in the array
  for (int i = 0; i < n; i++)
    count[a[i]]++;

  // Modifying the count array to get the indexes where the element
  // to be stored in the sorted array
  for (int i = 1; i <= max_ele; i++)
    count[i] = count[i] + count[i - 1];

  // First decrementing by 1 to make it 0-based indexing and traversing the original array
  // from last to start and storing at the correct index
  int output[n];
  for (int i = n - 1; i >= 0; i--)
    output[--count[a[i]]] = a[i];

  // Printing the Sorted Array
  for (int i = 0; i < n; i++)
    cout << output[i] << " ";
}
