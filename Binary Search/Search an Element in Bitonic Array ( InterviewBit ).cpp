// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.


// *************************************************************************************************************

// BITONIC SEQUENCE(OR ARRAY)
// A Bitonic Sequence is a sequence of numbers which is first strictly increasing
// then after a point(peak point) becomes strictly decreasing.


// Idea to Solve :-
// First finding the index of the peak element of the bitonic array and then calling two binary search on two
// subarrays [0,peak-1]{ ascending sorted } and [peak,n-1] { descending sorted }.


// Normal Binary Search funtion to search a target element in the array
int binary_search(vector<int> &nums, int left, int right, int target)
{
    int mid;

    while (left <= right)
    {
        mid = left + ((right - left) / 2);

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

// Binary Search function for descending sorted array to search a target element in the array
int binary_search2(vector<int> &nums, int left, int right, int target)
{
    int mid;

    while (left <= right)
    {
        mid = left + ((right - left) / 2);

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}


// Solution starts here
int Solution::solve(vector<int> &a, int x) {

    int n = a.size();
    int start = 0;
    int end = n - 1;
    int mid;

    // variable to store the index of the peak element of the Bitonic Array
    int peak;

    // Binary Search to find the index of the peak element of the bitonic array
    while (start <= end) {

        mid = start + ((end - start) / 2);

        // if mid is any element except the first and the last
        if (mid > 0 and mid < n - 1) {

            // if mid is greater than both of its neighbour
            if (a[mid] > a[mid + 1] and a[mid] > a[mid - 1]) {
                peak = mid;
                break;
            }

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
                peak = 0;
            else
                peak = 1;
        }
        // if mid is the last element of the array, so (mid+1) won't exist in this case
        else {
            if (a[n - 1] > a[n - 2])
                peak = n - 1;
            else
                peak = n - 2;
        }
    }

    // calling binary search on [0,peak-1] subarray
    int ind1 = binary_search(a, 0, (peak - 1 + n) % n, x);

    // calling binary search2 function on [peak,n-1] subarray as it is sorted in descending order
    int ind2 = binary_search2(a, peak, n - 1, x);

    if (ind1 != -1)
        return ind1;
    else if (ind2 != -1)
        return ind2;
    else
        return -1;

}

