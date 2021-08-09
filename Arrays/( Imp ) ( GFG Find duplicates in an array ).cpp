// Approach:-

//  The basic idea is to use a HashMap to solve the problem. But there is a catch, the numbers in the array
//  are from 0 to n-1, and the input array has length n. So, the input array(their indexes)
//  can be used as a HashMap.
//  While traversing the array, if an element a is encountered then increase the value of a'th indexed
//  element by n. The frequency can be retrieved by dividing the a'th indexed element by n.



// Algorithm :-

// WE WILL BE USING THE INDEXES OF THE ELEMENTS TO SOLVE THIS PROBLEM.

// 1) Traverse the given array from start to end.
// 2) Since every element is less than n, so we can use indexes to solve.
// 3) For every element a[i] in the array, increment the a[i]'th indexed element by n.
// 4) Now traverse the array again and print all those indices i for which a[i]/n is greater than 1,
//    which guarantees that the number n has been added to that index.



class Solution {
public:
    vector<int> duplicates(int a[], int n) {

        // to return the final result
        vector<int> ans;

        // in case of no answer, return {-1}
        vector<int> v;
        v.push_back(-1);

        // Traverse the given array from start to end then go to that
        // values as indexes and increment by n
        for (int i = 0; i < n; i++)
        {
            // to keep the index with in range [0,n-1]
            int index = a[i] % n;
            a[index] += n;
        }

        // Now check which value exists more than once by dividing with the size of array
        for (int i = 0; i < n; i++)
        {
            if ((a[i] / n) > 1)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            return v;

        return ans;
    }
};
