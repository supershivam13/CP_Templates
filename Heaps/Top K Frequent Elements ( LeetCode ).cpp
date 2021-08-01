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
    vector<int> topKFrequent(vector<int>& a, int k) {

        // MIN HEAP of pair { frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minh;

        // vector of integers to store the results
        vector<int> ans;

        int n = a.size();

        // map to store the frequency of each element
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        // Traversing the map and sorting the elements in heap on the basis of frequency of elements
        for (auto i : mp) {
            minh.push({i.second, i.first});

            if (minh.size() > k)
                minh.pop();
        }

        // inserting the elements of the heap to the ans vector
        while (minh.size() > 0) {
            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;

    }
};
