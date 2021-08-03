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


class Solution
{
public:
    vector <int> calculateSpan(int a[], int n)
    {
        // vector to return and store the final result
        vector<int> v;

        // stack to store pairs { element , index}
        stack < pair<int, int> > s;

        // Finding Nearest Greater to Left
        for (int i = 0; i < n; i++) {

            if (s.size() == 0)
                v.push_back(-1);

            // comparision is done using elements a[i] and
            // indexes i of NGL are getting stored in vector v
            else if (s.size() > 0 and s.top().first > a[i])
                v.push_back(s.top().second);

            else if (s.size() > 0 and  s.top().first <= a[i]) {

                while (s.size() > 0 and s.top().first <= a[i])
                    s.pop();

                if (s.size() == 0)
                    v.push_back(-1);
                else
                    v.push_back(s.top().second);
            }

            // pushing the { elemennt, index } into the stack after its processing is done
            s.push({a[i], i});
        }

        // v[i] stores the index of the NGL element for a[i], if does not exist then -1

        // calculating the distance between the Nearest Greater to Left
        // or you can say consecutive smaller or equal before
        for (int i = 0; i < v.size(); i++)
            v[i] = i - v[i];

        return v;
    }
};
