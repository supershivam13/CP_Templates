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


// IDEA - make a map of {element as key , NGE as value} for all the elements of the second array,
//        and then traverse the first array and storing the NGE in the result vector


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& a) {

        // to return the final result
        vector<int> v;

        // map of {element as key , NGE as value}
        unordered_map<int, int> mp;
        stack<int> s;

        // Preparing a map of {element as key , NGE as value} for all the elements of second array
        // ( Next Greater Element Algorithm on the second array )
        for (int i = a.size() - 1; i >= 0; i--) {

            if (s.size() == 0)
                mp[a[i]] = -1;

            else if (s.size() > 0 and s.top() > a[i])
                mp[a[i]] = s.top();

            else if (s.size() > 0 and s.top() <= a[i]) {

                while (s.size() > 0 and s.top() <= a[i])
                    s.pop();

                if (s.size() == 0)
                    mp[a[i]] = -1;
                else
                    mp[a[i]] = s.top();
            }

            s.push(a[i]);
        }

        // traversing the first array and storing the NGE value of the elements in the vector
        // ( Guaranteed that all elements in first array is also present in second array )
        for (int i = 0; i < nums.size(); i++)
            v.push_back(mp[nums[i]]);

        return v;
    }
};
