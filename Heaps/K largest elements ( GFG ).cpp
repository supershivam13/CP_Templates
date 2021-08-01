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
    vector<int> kLargest(int arr[], int n, int k)
    {
        // vector of integers to store the results
        vector<int> ans;
        minheap minh;

        for (int i = 0; i < n; i++) {
            minh.push(arr[i]);

            // only keeping the largest k elements in the heap
            if (minh.size() > k)
                minh.pop();
        }

        // inserting the elements of the heap to the ans vector
        while (k--) {
            ans.push_back(minh.top());
            minh.pop();
        }
        
        reverse(ans.begin(),ans.end());

        return ans;
    }

};
