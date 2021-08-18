// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.


// *************************************************************************************************************

// Sometimes, we can apply binary search to a unsorted array also.
// This question is one such example.



class Solution {
public:
    int findPeakElement(vector<int>& a) {

        int n = a.size();

        if (n == 1)
            return 0;

        int start = 0;
        int end = n - 1;
        int mid;

        // Binary Search
        while (start <= end) {

            mid = start + ((end - start) / 2);

            // if mid is any element except the first and the last
            if (mid > 0 and mid < n - 1) {

                // if mid is greater than both of its neighbour
                if (a[mid] > a[mid + 1] and a[mid] > a[mid - 1])
                    return mid;

                // move to the more promising halve of array, where there is more chances of finding a peak element
                // if right neighbour is greater, so it has more chances of being a peak element, so moving right
                else if (a[mid] < a[mid + 1])
                    start = mid + 1;
                else
                    end = mid - 1;
            }

            // if mid is first element of the array, so (mid-1) won't exist in this case
            else if (mid == 0) {
                if (a[0] > a[1])
                    return 0;
                else
                    return 1;
            }
            // if mid is the last element of the array, so (mid+1) won't exist in this case
            else {
                if (a[n - 1] > a[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
        }

        return -1;

    }
};
