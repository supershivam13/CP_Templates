// STACK QUESTIONS

// IDENTIFICATION
// Brute Force - O( N^2 ) { dependent nested loop } { j loop is dependent on i loop }

// Example - for(int i=0;i<n;i++){
//              inside for loop is dependent on i loop

//              a) for(int j=0; j<=i; j++)
//              b) for(int j=i; j>=0; j--)
//              c) for(int j=i; j<=n; j++)
//              d) for(int j=n; j>=i; j++)
//              e) some more like this
//
//           }

// **********************************************************************************************

// MAXIMUM AREA OF RECTANGLE IN BINARY MATRIX

// IDEA -
// We will consider each row ( after some calculations ) as an array of histogram and
// calculate the max area from each row
// and then select the max of all the areas.

class Solution {
public:

    // Normal Maxmium Area Histogram function
    int MaxAreaHistogram(vector<int>& a) {

        // vectors to store the indexes of the NSL and NSR
        vector<int> NSL, NSR;

        stack<pair<int, int>> s1, s2;
        int n = a.size();

        // Finding the indexes of the NSL
        for (int i = 0; i < n; i++) {

            if (s1.size() == 0)
                NSL.push_back(-1);

            // comparision is done using elements a[i] and
            // indexes i of NSL are getting stored in vector NSL
            else if (s1.size() > 0 and s1.top().first < a[i])
                NSL.push_back(s1.top().second);

            else if (s1.size() > 0 and s1.top().first >= a[i]) {

                while (s1.size() > 0 and s1.top().first >= a[i])
                    s1.pop();

                if (s1.size() == 0)
                    NSL.push_back(-1);
                else
                    NSL.push_back(s1.top().second);
            }

            // pushing the { elemennt, index } into the stack after its processing is done
            s1.push({a[i], i});
        }

        // NSL Vector is ready now


        // Now, Finding the indexes of the NSR
        for (int i = n - 1; i >= 0; i--) {

            // Assuming a 0-height building at the index n, instead of -1 to help in calculations
            if (s2.size() == 0)
                NSR.push_back(n);

            // comparision is done using elements a[i] and
            // indexes i of NSR are getting stored in vector NSR
            else if (s2.size() > 0 and s2.top().first < a[i])
                NSR.push_back(s2.top().second);

            else if (s2.size() > 0 and s2.top().first >= a[i]) {

                while (s2.size() > 0 and s2.top().first >= a[i])
                    s2.pop();

                // Assuming a 0-height building at the index n, instead of -1 to help in calculations
                if (s2.size() == 0)
                    NSR.push_back(n);
                else
                    NSR.push_back(s2.top().second);
            }

            // pushing the { elemennt, index } into the stack after its processing is done
            s2.push({a[i], i});
        }

        reverse(NSR.begin(), NSR.end());

        // NSR Vector is ready now



        int max_area = 0;

        // calculating the areas of the possible rectangles and storing the max area
        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;

            // a[i] = height of the rectangle
            max_area = max(max_area, width * a[i]);
        }

        return max_area;
    }



    // SOLUTION ( function call from main ) STARTS FROM HERE

    int maximalRectangle(vector<vector<char>>& matrix) {

        int row = matrix.size();

        // edge case when empty matrix is given
        if (row == 0)
            return 0;

        int col = matrix[0].size();

        // vector to make the histogram array which will be passed to MAH function
        // initialised with size = col and value = 0
        vector<int> v(col, 0);

        int temp = 0;
        int ans = 0;

        for (int i = 0; i < row; i++) {

            // making the histogram array to pass in the MAH function
            for (int j = 0; j < col; j++) {

                // if 1 is there, then add in the previous value (i.e addition of one floor)
                if (matrix[i][j] == '1')
                    v[j] += 1;
                // else 0 is there, so making v[i] = 0 as histogram can't be flying
                else
                    v[j] = 0;
            }

            // calculating the Maximum area from the histogram vector v
            temp = MaxAreaHistogram(v);

            // taking the max areas of all possible areas
            ans = max(ans, temp);
        }

        return ans;
    }
};
