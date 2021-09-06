// Time Complexity - O ( N*logN)
// Space Complexity - O(1)

class Solution {
public:
    //Function to merge two sorted arrays in O(1) space
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // first pointer on last element of first array
        int i = n - 1;
        // second pointer on first element of second array
        int j = 0;

        while (i >= 0 and j < m) {

            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

            i--;
            j++;
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
