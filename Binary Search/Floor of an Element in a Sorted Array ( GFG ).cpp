// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


class Solution {
public:
    int findFloor(vector<long long> v, long long n, long long x) {

        int start = 0;
        int end = n - 1;
        int mid;

        // Variable to store the index of the floor element of x
        // initialised with -1, so that if no element <= x, then return -1.
        int res = -1;

        // Binary Search
        while (start <= end) {

            mid = start + ((end - start) / 2);

            if (v[mid] == x)
                return mid;

            else if (v[mid] > x)
                end = mid - 1;

            // when moving to right, we store the indexes of the potential elments which can be floor
            else {
                res = mid;
                start = mid + 1;
            }
        }

        return res;

    }
};
