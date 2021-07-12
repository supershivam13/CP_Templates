#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)
#define all(v)          v.begin(),v.end()
#define pb              push_back


class Solution {
public:
    int lengthOfLIS(vector<int>& a) {

        int n = a.size();

        // LIS array to store the length LIS found till now
        int lis[n];

        // Initialising the LIS array with as each element is a LIS in itself
        f(i, n)
        lis[i] = 1;

        // Compute optimized LIS values in bottom up manner

        // first loop covers all the elements of the array
        for (int i = 1; i < n; i++) {
            // second loop checks for previous elemens of a[i] to get the max value of LIS by including a[i]
            for (int j = 0; j < i; j++)

                // if prev element is smaller and including it will increase the LIS obtained till now
                if (a[i] > a[j] and lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }

        // Getting the maximum value of LIS from the lis array ( FINAL RESULT )
        return *max_element(lis, lis + n);

    }
};
