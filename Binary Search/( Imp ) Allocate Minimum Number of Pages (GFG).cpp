// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// 1) When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.


// 2) Binary Search can also be applied when the answer space is monotonic. That is for a point A in the answer
// space, all values >= A or all values <= A satisfies the conditions and hence, we use Binary Search to find
// point A {which is the answer}. ( Example - Allocate Minimum Number of Pages )

// *************************************************************************************************************


class Solution
{
public:

    // isvalid function returns true if the arrangement is possible by assigning 'mid' number of pages
    bool isvalid(int a[], int n, int m, int pages) {

        int student = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];

            // if sum > pages, then need of a new student to assign books and new student starts with a[i] pages
            if (sum > pages) {
                student++;
                sum = a[i];
            }

            // if any point of time, students required becomes gretaer than m, return false
            if (student > m)
                return false;
        }

        return true;
    }

    // Solution Starts here
    int findPages(int a[], int n, int m)
    {
        // if no. of books is less than students, then no arrangement possible
        if (n < m)
            return -1;

        // lowest number of pages a student have to read { as the book with max pages will have to be allocated
        // to a student }
        int low = *max_element(a, a + n);

        int high = accumulate(a, a + n, 0);
        int mid;
        int res = -1;

        // Binary Search
        while (low <= high) {

            mid = low + ((high - low) / 2);

            // isvalid function returns true if the arrangement is possible by assigning 'mid' number of pages
            // if true, then store the result and move to left part to find more better answer.
            if (isvalid(a, n, m, mid) == true) {
                res = mid;
                high = mid - 1;
            }
            // else we need to increase the pages capacity of student, so moving in right part
            else
                low = mid + 1;

        }

        return res;

    }
};
