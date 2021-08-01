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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        minheap minh;

        for (int i = 0; i < nums.size(); i++) {
            minh.push(nums[i]);

            if (minh.size() > k)
                minh.pop();
        }

        return minh.top();
    }
};
