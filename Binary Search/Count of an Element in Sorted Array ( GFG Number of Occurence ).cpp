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
    int count(int a[], int n, int target) {

        // variables to store the first and last occurence
        int first = -1;
        int last = -1;

        int start = 0;
        int end = n - 1;

        // Binary Search for first occcurence of target element
        while (start <= end) {

            int mid = start + ((end - start) / 2);

            // Only difference is on founding the target element, we store the result
            // and keep our search continue on the left halve as we are looking for first occurence
            if (target == a[mid]) {
                first = mid;
                end = mid - 1;
            }
            else if (target > a[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }

        // re-initialising the values of start and end
        start = 0;
        end = n - 1;

        // Binary Search for last occcurence of target element
        while (start <= end) {

            int mid = start + ((end - start) / 2);

            // Only difference is on founding the target element, we store the result
            // and keep our search continue on the right halve as we are looking for last occurence
            if (target == a[mid]) {
                last = mid;
                start = mid + 1;
            }
            else if (target > a[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }

        // if not found, return 0
        if (first == -1 or last == -1)
            return 0;
        else
            return (last - first + 1);

    }
};
