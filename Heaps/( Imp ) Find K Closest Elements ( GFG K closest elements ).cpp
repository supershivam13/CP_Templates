// HEAP QUESTIONS

// IDENTIFICATION
// Two keywords occurs together - 1) K                2) Largest/Smallest

// a) K + Largest =  MIN HEAP
// b) K + Smallest = MAX_HEAP

// **********************************************************************************************

// Time Complexity - O( NlogK )
// ( A for loop of N complexity and we never stores more than k elements in heap at any moment
// so, pushing an elements take logK time, so overall TC - O( NlogK ) )

class Solution {
public:
    vector<int> printKClosest(vector<int> a, int k, int x) {
        
        int n = a.size();
        vector<int> ans;
        
        // making a Max heap of pair { absolute difference, element }
        priority_queue<pair<int, int>> mx;

        for (int i = 0; i < n; i++) {

            // acc. to question, If X is present in the array, then it need not be considered
            if (abs(x - a[i]) == 0)
                continue;

            // sorting will be done on the basis of first element of pair
            // in case first elements of pair are equal, then sorting done on basis of second

            // acc. to Question, we need larger element before in case of same absolute difference
            // so, storing the second as negative, so to reverse the comparator function of sorting
            mx.push({abs(x - a[i]), -a[i]});

            if (mx.size() > k)
                mx.pop();
        }

        while (mx.size() > 0) {     // inserting the elements of the heap to the ans vector
            ans.push_back(-1 * (mx.top().second));
            mx.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
