#include<bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ff first
#define ss second
#define endl '\n'
#define mod (int)1e9+7
using namespace std;

// Time Complexity - O(N*M)
// where N,M are the lengths of the text string and the pattern string

// T = Text, P = Pattern to match
string T , P;
int LP , LT;

// function to check whether the window sting matches the patter or not
bool match(int L , int R)
{
    for (int i = 0; i < LP; i++)
        if (T[L + i] != P[i]) return false;

    return true;
}

int main()
{
    int t;
    cin >> t;

    cin.ignore();

    while (t--)
    {
        getline(cin , T);
        getline(cin , P);
        LP = P.size();
        LT = T.size();

        for (int L = 0 , R = LP - 1; R < LT; L++ , R++)

            if (match(L , R))
                cout << L << " ";

        cout << endl;
    }
}
