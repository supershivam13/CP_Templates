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

class Solution{
public:
    vector<int> nextLargerElement(vector<int> arr) {
        
        int n = arr.size();
        stack<int> s;
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--) {    // traversing the array from end to start

            // if no elements in stack, then ans is -1  (given in question, if no NGE, then -1)
            if (s.size() == 0)
                ans.push_back(-1);

            // if size>0 and top element is greater than a[i], then s.top() is answer
            else if (s.size() > 0 and s.top() > arr[i])
                ans.push_back(s.top());

            // if size>0 and top element is smaller or equal to a[i]
            else if (s.size() > 0 and s.top() <= arr[i]) {

                // pop elements until stack is empty or top element becomes greater than a[i]
                while (s.size() > 0 and s.top() <= arr[i])
                    s.pop();

                if (s.size() == 0)
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            
            s.push(arr[i]);   // inserting the element in the stack after its processing for NGE is done
        }

        reverse(ans.begin(), ans.end());    // reversing the result vector
        return ans;
    }
};
