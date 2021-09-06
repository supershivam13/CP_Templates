
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Two pointer technique
        int f = m - 1;
        int s = n - 1;

        int ind = m + n - 1;

        // will run until one of the pointers ( f or s ) becomes less than zero
        while (f >= 0 and s >= 0) {
            nums1[ind] = max(nums1[f], nums2[s]);
            if (nums1[f] >= nums2[s]) {
                f--;
            }
            else {
                s--;
            }

            ind--;
        }

        // Uptill here, one of the pointer has became zero, so only one while loop will execute out of two
        // while loops below

        while (f >= 0) {
            nums1[ind] = nums1[f];
            ind--;
            f--;
        }

        while (s >= 0) {
            nums1[ind] = nums2[s];
            ind--;
            s--;
        }

    }
};
