// SWAP SORT

// Used in 1-N type questions to get the elements at their correct index
// i.e at i-th index, element (i+1) should be present. If this element is not present
// in the array, then some duplicate element will be present there.

// Time Complexity - O(n) { O(2n - 2) to be precise }
// Space Complexity - O(1)

// Caution -
// can not be used when the array is read-only or Array can not be modified.


class Solution {
public:
    vector<int> duplicates(int a[], int n) {

        int i = 0;
        // to return the final result
        vector<int> ans;

        // in case of no answer, return {-1}
        vector<int> v;
        v.push_back(-1);


        // Swap Sort Algorithm - O(N)

        while (i < n) {

            // Here elements are from [0,N-1], so comparing a[i] with a[a[i]]
            // instead of a[i] with a[a[i]-1]
            if (a[i] != a[a[i]])
                swap(a[i], a[a[i]]);
            else
                i++;
        }

        // storing the duplicate numbers
        for (int i = 0; i < n; i++) {
            if (a[i] != i)
                ans.push_back(a[i]);
        }

        // if no duplicate numbers are found, then return -1
        if (ans.size() == 0)
            return v;

        sort(ans.begin(), ans.end());

        // Now, removing the multiple occurences of the same duplicate number

        // unique() returns the iterator to the last element not removed
        // unique() works on sorted array only
        auto it = unique(ans.begin(), ans.end());

        // l stores the length of vector upto which unique elements are present
        int l = it - ans.begin();

        // resizing the vector only upto length and erasing the remaining elements
        ans.resize(l);

        return ans;
    }
};
