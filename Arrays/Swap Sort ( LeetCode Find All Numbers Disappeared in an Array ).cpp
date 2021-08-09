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
    vector<int> findDisappearedNumbers(vector<int>& a) {

        vector<int> miss;
        int i = 0;
        int n = a.size();

        // Swap Sort Algorithm
        while (i < n) {

            if (a[i] != a[a[i] - 1])
                swap(a[i], a[a[i] - 1]);
            else
                i++;
        }

        for (int i = 0; i < n; i++)
            if (a[i] != i + 1)
                miss.push_back(i + 1);

        return miss;

    }
};
