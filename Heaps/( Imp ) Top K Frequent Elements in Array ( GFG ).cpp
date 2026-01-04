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
    vector<int> topKFreq(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;   // {element : frequency}
        for(auto ele : nums)
            mp[ele]++;
        
        // MIN HEAP of pair {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        // Traversing the map and sorting the elements in heap on the basis of frequency of elements
        for (auto p : mp) {
            pq.push({p.second, p.first});

            // sorting will be done on the basis of first element of pair
            // in case first elements of pair are equal, then sorting done on basis of second
            // so the pair with smaller second element will be popped ( as per requirement of ques )

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (pq.size() > 0) {     // inserting the elements of the heap to the 'ans' vector
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
