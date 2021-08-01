// HEAP QUESTIONS

// IDENTIFICATION
// Two keywords occurs together - 1) K                2) Largest/Smallest

// a) K + Largest =  MIN HEAP
// b) K + Smallest = MAX_HEAP

// **********************************************************************************************

// Time Complexity - O( NlogK )
// ( A for loop of N complexity and we never stores more than k elements in heap at any moment
// so, pushing an elements take logK time, so overall TC - O( NlogK ) )


#define vvi             vector<vector<int>>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // MAX heap to store the pair { distance, {x,y} }
        priority_queue<pair<int, pair<int, int>>> maxh;

        // to store the final result
        vvi ans;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            // squaring the distances will not change the order, so storing (x*x + y*y) as key
            // instead of sqrt(x*x + y*y)
            maxh.push({(x * x) + (y * y), {x, y}});

            // sorting will be done on the basis of first element of pair
            // in case first elements of pair are equal, then sorting done on basis of second

            if (maxh.size() > k)
                maxh.pop();
        }

        // storing the result in the 'ans' vector from the heap
        while (maxh.size() > 0) {

            pair<int, int> xy = maxh.top().second;
            vector<int> tmp;
            tmp.push_back(xy.first);
            tmp.push_back(xy.second);
            ans.push_back(tmp);

            maxh.pop();
        }

        return ans;
    }
};
