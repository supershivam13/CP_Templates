// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.


// *************************************************************************************************************
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {

        // m = no. of rows and n = no. of columns
        int m = a.size();
        int n = a[0].size();

        int start = 0;
        int end = (m * n) - 1;
        int mid;

        // Binary Search in 2D Sorted Matrix (row wise and column wise sorted)
        while (start <= end) {

            mid = start + ((end - start) / 2);
            // getting the proper row and column index to store the value of the element at mid
            int mid_val = a[mid / n][mid % n];

            if (mid_val == x)
                return true;

            else if (mid_val > x)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;
    }
};
