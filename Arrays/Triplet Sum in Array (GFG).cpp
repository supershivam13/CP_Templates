class Solution {
public:
    bool find3Numbers(int a[], int n, int X)
    {
        sort(a, a + n);

        for (int i = 0; i < n - 2; i++) {

            int l = i + 1;
            int r = n - 1;

            // Here l can't be equal to r as we need three different-index elements to sum up to X
            while (l < r) {
                if (a[i] + a[l] + a[r] == X)
                    return true;
                else if (a[i] + a[l] + a[r] < X)
                    l++;
                else
                    r--;
            }
        }

        return false;
    }
};
