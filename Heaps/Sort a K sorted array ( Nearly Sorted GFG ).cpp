// HEAP QUESTIONS

// IDENTIFICATION
// Two keywords occurs together - 1) K                2) Largest/Smallest

// a) K + Largest =  MIN HEAP
// b) K + Smallest = MAX_HEAP

// ****************************************************************************************


// Time Complexity - O( NlogK )
// ( A for loop of N complexity and we never stores more than k elements in heap at any moment
// so, pushing an elements take logK time, so overall TC - O( NlogK ) )


#define minheap         priority_queue<int,vector<int>,greater<int>>

class Solution
{
public:

    vector <int> nearlySorted(int a[], int n, int k) {

        // vector of integers to store the results
        vector<int> ans;
        minheap mh;

        for (int i = 0; i < n; i++) {
            mh.push(a[i]);

            // since the array is k sorted array, so when the heap size is more than k,
            // upto then the smallest correct must be at the top of the minheap
            if (mh.size() > k) {
                ans.push_back(mh.top());
                mh.pop();
            }
        }

        // inserting the remaining elements of the heap to the ans vector
        while (k--) {
            ans.push_back(mh.top());
            mh.pop();
        }

        return ans;
    }
};
