// Method - 1

// Time - O(N)
// Space - O(N)


class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        map<int, int> m;    // { element : frequency }

        for (auto x : nums)
            m[x]++;

        for (auto p : m)    
            if (p.second > n / 2)    // if any frequency > n/2, then return that element
                return p.first;

        return -1;
    }
};


// ***************************************************************


// Method - 2  (Space Optimised) - Moore's Algorithm

// Time - O(N)
// Space - O(1)

// Idea to solve -
// To be the Majority element, element has to occure MORE THAN N/2 times.
// So the majority element will have a counter which increases by 1 on founding the same element
// and decreases if we found any other element other than majority element.
// For the correct majority element, counter will not reach to zero.

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int maj = nums[0];    // Assumed majority element
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == maj)
                count++;
            else
                count--;

            // on reaching count zero, we change the assumed majority element
            if (count == 0) {
                maj = nums[i];
                count = 1;
            }
        }
        
        return maj;
   }
};
