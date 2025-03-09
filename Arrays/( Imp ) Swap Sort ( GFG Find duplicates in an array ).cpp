// SWAP SORT - O(N) - not exactly sorting -  Aditya Verma

// Used in 1-N type questions to get the elements at their correct index
// i.e at i-th index, element (i+1) should be present. If this element is not present
// in the array, then some duplicate element will be present there.

// NOTE: 
// This works with multiple missing and duplicate numbers.

// Time Complexity - O(N)
// Space Complexity - O(1)

// Caution -
// can not be used when the array is read-only or Array can not be modified.


class Solution {
public:
    vector<int> findDuplicates(vector<int> a) {

        vector<int> ans;
        set<int> s;
        int n = a.size();

        // Swap Sort Algorithm - O(N)
        int i = 0;
        
        while (i < n) {

            // Here elements are from [0,N-1], so comparing a[i] with a[a[i]]
            // instead of a[i] with a[a[i]-1] ---> this occurs in case of [1,N]
            if (a[i] != a[a[i]])    // {JO ISKI SAHI JAGAH PE BAITHA HAI, KYA WO WAHI HAI?}
                swap(a[i], a[a[i]]);
            else
                i++;
        }

        // storing the duplicate numbers in 's' set
        for (int i = 0; i < n; i++)
            if (a[i] != i)
               s.insert(a[i]);

        for(auto ele : s)
            ans.push_back(ele);

        return ans;
    }
};
