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

// Time Complexity of below Solution =  O( log(m+n) )


// Ex: nums1 = [7, 12, 14, 15]
//     nums2 = [1, 2, 3, 4, 9, 11]

// Partition:        7  |   12 14 15
//             1 2 3 4  |   9  11



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums1 should be of smaller size, if not, call recursively with arrays swapped in parameters
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), int n2 = nums2.size();
        // low, high indicates the minimum and maximum elements that can be taken from the nums1 array in the partition
        int low = 0, high = n1;

        while (low <= high) {

            int cut1 = low + ((high - low) / 2);
            // 'cut1' number of elements are taken from nums1 array, so 'cut2' number of elements
            // should be taken from the nums2 array
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;

            // Handling corner cases
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            // Handling corner cases
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            // if this condition is true, then our partition is correct, and now just need to return the median
            if (left1 <= right2 && left2 <= right1) {

                // if sum of sizes of both arrays is even, then there will be two median elements
                if ( (n1 + n2) % 2 == 0 )
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            // need to go left to make left1 smaller than right2
            else if (left1 > right2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};
