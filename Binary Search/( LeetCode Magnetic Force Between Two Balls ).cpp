// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// 1) When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.


// 2) Binary Search can also be applied when the answer space is monotonic. That is for a point A in the answer
// space, all values >= A or all values <= A satisfies the conditions and hence, we use Binary Search to find
// point A {which is the answer}. ( Example - Allocate Minimum Number of Pages{GFG}, Magnetic Force Between
// Two Balls{LeetCode}, Aggressive Cows{SPOJ} )

// *************************************************************************************************************

// This question is same as Aggressive Cows.


class Solution {
public:

    // isvalid function returns true if it is possible to place m balls with minimum distance 'dist'
    bool isvalid(vector<int>&a, int n, int m, int dist) {

        int count = 1;
        // variable to store the position of the last placed ball
        int last_place = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] - last_place >= dist) {
                count++;
                last_place = a[i];
            }
        }

        // if we are able to place m balls with minimum distance 'dist' in b/w them, then return true.
        if (count >= m)
            return true;
        else
            return false;
    }

    // Solution starts here
    int maxDistance(vector<int>& a, int m) {

        int n = a.size();
        sort(a.begin(), a.end());

        // position of baskets are distinct, so minimum distance between any two balls can be 1.
        int low = 1;

        // maximum distance between two balls = distance between first and last basket
        int high = a[n - 1] - a[0];

        int mid;
        int res = -1;

        // Binary Search
        while (low <= high) {

            mid = low + ((high - low) / 2);

            // isvalid function returns true if it is possible to place m balls with minimum distance 'mid'
            // if true, store the result and move to right part as we want to maximise this 'mid'
            if (isvalid(a, n, m, mid) == true) {
                res = mid;
                low = mid + 1;
            }
            // else move to the left part as we need to reduce the distance between the balls
            else
                high = mid - 1;
        }

        return res;
    }
};
