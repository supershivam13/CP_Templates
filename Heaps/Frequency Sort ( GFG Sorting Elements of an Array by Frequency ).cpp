// HEAP QUESTIONS

// IDENTIFICATION
// Two keywords occurs together - 1) K                2) Largest/Smallest

// a) K + Largest =  MIN HEAP
// b) K + Smallest = MAX_HEAP

// **********************************************************************************************

// Time Complexity - O( NlogK )
// ( A for loop of N complexity and we never stores more than k elements in heap at any moment
// so, pushing an elements take logK time, so overall TC - O( NlogK ) )



#include<iostream>
#include <bits/stdc++.h>

#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)
#define arrin(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" "
#define print2d(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<"\n";}
#define w(x)            int x; cin>>x; while(x--)


using namespace std;

int main()
{
    w(t) {
        int n;
        cin >> n;
        int a[n];
        arrin(a, n);

        // map to store the frequency of each element
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        // MAX heap to store pair { frequency, element }
        priority_queue<pair<int, int>> maxh;

        // sorting will be done on the basis of first element of pair
        // in case first elements of pair are equal, then sorting done on basis of second

        // acc. to question, we need smaller element before in case of same frequency
        // so, storing the second as negative, so to reverse the comparator function of sorting
        // ( otherwise pair with larger second value will be above in heap )
        for (auto i : mp)
            maxh.push({i.second, -i.first});

        while (maxh.size() > 0) {
            int freq = maxh.top().first;

            // multiplying with -1 so as to obtain the original element
            int num = -maxh.top().second;

            while (freq) {
                cout << num << " ";
                freq--;
            }

            maxh.pop();
        }
        cout << endl;

    }
    return 0;
}
