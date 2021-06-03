// Code for Disjoint Set Union data structure.
// Amortized Time Complexity - O(1).
// Note: Amortized complexity is the total time per operation, evaluated over a sequence of multiple operations. A single call might take O(logn) in the worst case,
// but if we do m such calls back to back we will end up with an average time of O(α(n)).

// to store the set ID(parent) of each set

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'

using namespace std;


int parent[100001];

// to store the size of set of each set ID(parent)
int siz[100001];


// to find the set ID(parent) of v
int findSet(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

// to initialize sets of one node (trees of single node) ( only used during initialisation one time )
void makeSet(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

// to merge two sets of elements a and b
// ( Merging smaller set into bigger set as it is also used in DP Optimization of trees.
// Also height of the resultant tree will not exceed O(logN). )
void unionSets(int a, int b)
{
    // finding the parent of both elements
    a = findSet(a);
    b = findSet(b);


    if (a != b)
    {
        if (siz[a] < siz[b]) {
            parent[a] = b;
            siz[b] += siz[a];
        }


        else {
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
}

int main() {

    // number of nodes
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int max = 0;

    for (int i = 0; i < n; i++) {
        if (s.at(i) == '1') {
            max = 1;
        }
    }


    for (int i = 0; i < n; i++)
        makeSet(i);

    for (int i = 1; i < n; i++) {

        if (s.at(i) == '1') {

            if (s.at(i - 1) == '1') {
                unionSets(i, i - 1);
            }

            int par = findSet(i);
            if (siz[par] > max) {
                max = siz[par];
            }

        }



    }



    int a, b;

    while (k--) {
        cin >> a;

        if (a == 1) {
            cout << max << endl;
        }
        else {
            cin >> b;
            s.at(b - 1) = '1';

            if (b - 2 >= 0 and s.at(b - 2) == '1' ) {
                unionSets(b - 1, b - 2);
            }

            if (b < n and s.at(b) == '1') {
                unionSets(b, b - 1);
            }

            int p1 = findSet(b - 1);

            if (max < siz[p1])
                max = siz[p1];



        }

    }

}
