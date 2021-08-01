// HEAP QUESTIONS

// IDENTIFICATION
// Two keywords occurs together - 1) K                2) Largest/Smallest

// a) K + Largest =  MIN HEAP
// b) K + Smallest = MAX_HEAP

// ****************************************************************************************

// Time Complexity - O( NlogK )
// ( A for loop of N complexity and we never stores more than k elements in heap at any moment
// so, pushing an elements take logK time, so overall TC - O( NlogK ) )


class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {

        // vector of integers to store the results
        vector<int> ans;

        // making a max heap of pair { absolute difference, element }
        priority_queue<pair<int, int>> mx;
        int n = a.size();

        for (int i = 0; i < n; i++) {

            // sorting will be done on the basis of first element of pair
            // in case first elements of pair are equal, then sorting done on basis of second
            mx.push({abs(x - a[i]), a[i]});

            // only keeping the closest k elements in the heap
            if (mx.size() > k)
                mx.pop();
        }
        
        // inserting the remaining elements of the heap to the ans vector
        while (mx.size() > 0) {
            ans.push_back(mx.top().second);
            mx.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
