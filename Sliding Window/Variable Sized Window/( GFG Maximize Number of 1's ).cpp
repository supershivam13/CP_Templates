// VARIABLE SIZED SLIDING WINDOW

//  i = start of window
//  j = end of window
//  window size = j-i+1


// IDEA to Solve -
// Largest window size which has <= 'm' number of zeroes. As soon as the count of zeroes in window becomes > 'm'
// then we start shrinking our window.

class Solution {
public:
    int findZeroes(int a[], int n, int m) {

        int i = 0, j = 0, ans = 0;
        // number of zeroes present in the window
        int zero = 0;

        while (j < n) {

            if (a[j] == 0)
                zero++;

            if (zero > m) {

                while (zero > m) {

                    if (a[i] == 0)
                        zero--;

                    i++;
                }
            }

            // at this point of time, number of zeroes is getting <= 'm' every time
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
