// These 3 parameters are always there in any Segment Tree function
// Segment Index (idx)
// Segment Start (start)
// Segment End (end)

// If using 0-based indexing for the segment tree array:
// Current node index = i
// Left child  = 2*i + 1
// Right child = 2*i + 2


#include <bits/stdc++.h>
using namespace std;

int a[1000006];                // lim = 10*6, array for taking input
int segTree[4 * 1000006];      // size should be 4*n, so making it of 4 * 10^6

// Function to build the segment tree array before processing queries
void build(int idx, int start, int end) {

    if (start == end) {					 // Only one element (Leaf Node)
        segTree[idx] = a[start];
        return;
    }

    int mid = start + ((end - start) / 2);

    build(2 * idx + 1, start, mid);
    build(2 * idx + 2, mid + 1, end);

    segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
}


// Function to answer a query in O(logN) time ( Brute Force takes O(N) to process a single query )
int query(int idx, int start, int end, int left, int right){

    if(left > end || right < start)         // if queried range is completely out of range[start, end]
        return INT_MAX;
     
    if( start >= left && right >= end)      // if queried ranges lies completely in range[start, end]
        return segTree[idx];
    
    int mid = start + ((end - start) / 2);

    int leftValue = query(2 * idx + 1, start, mid, left, right);
    int rightValue = query(2 * idx + 2, mid + 1, end, left, right);

    return min(leftValue, rightValue);
}

// CODE starts here
int main(){
    int n;
    cin >> n;
	
    for(int i = 0; i<n; i++)
    	cin >> a[i];

    build(0, 0, n-1);			 // Built using 0-based indexing

    int q;						 // Number of queries  (return the minimum element in the range [L,R])
    cin >> q;
    while (q--) {

        int left, right;
        cin >> left >> right;

        cout << query(0, 0, n-1, left, right) << endl;
    }
}
