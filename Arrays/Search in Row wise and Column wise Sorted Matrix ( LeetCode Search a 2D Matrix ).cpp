// Time Complexity -  O(m+n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {

        // m = no. of rows and n = no. of columns
        int m = a.size();
        int n = a[0].size();

        // Starting from the top right corner( it acts as the mid)
        int i = 0;
        int j = n - 1;

        // while i and j are within the bounds of the matrix
        while (i<m and j >= 0) {

            if (a[i][j] == x)
                return true;

            // since the matrix is row-column wise sorted, so if a[i][j] > target,
            // then moving one column backwards
            else if (a[i][j] > x)
                j--;
            // else moving one row downside
            else
                i++;
        }

        return false;
    }
};
