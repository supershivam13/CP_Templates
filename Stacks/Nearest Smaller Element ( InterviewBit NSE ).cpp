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


vector<int> Solution::prevSmaller(vector<int> &a) {

    stack<long long> s;
    vector<int> v;

    int n = a.size();

    // traversing the array from start to end
    for (int i = 0; i < n; i++) {

        // if no elements in stack, then ans is -1
        if (s.size() == 0)
            v.push_back(-1);

        // if size>0 and top element is smaller than a[i], then s.top() is answer
        else if (s.size() > 0 and s.top() < a[i])
            v.push_back(s.top());

        // if size>0 and top element is greater or equal to a[i]
        else if (s.size() > 0 and s.top() >= a[i]) {

            // pop elements until stack is empty or top element becomes smaller than a[i]
            while (s.size() > 0 and s.top() >= a[i])
                s.pop();

            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());

        }

        // inserting the element in the stack after its processing for NSE is done
        s.push(a[i]);
    }

    return v;


}
