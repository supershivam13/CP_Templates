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

// MAXIUMU AREA HISTOGRAM

// IDEA -
// Finding the indexes of Nearest Smallest to Left (NSL) and Nearest Smallest to Right (NSR)
// and calculating the width of the possible rectanges for all elements of array a[i], multiplying it
// with the a[i] (height of the rectangle ) and returning the max area


class Solution {
public:
    int largestRectangleArea(vector<int>& a) {

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
};
