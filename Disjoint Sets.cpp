// Code for Disjoint Set Union data structure.
// Amortized Time Complexity - O(1).
// Note: Amortized complexity is the total time per operation, evaluated over a sequence of multiple operations. A single call might take O(logn) in the worst case,
// but if we do m such calls back to back we will end up with an average time of O(α(n)).

// to store the set ID(parent) of each set
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
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        makeSet(i);


    // number of relations / edges
    int m;
    cin >> m;

    int a, b;

    while (m--) {
        cin >> a >> b;

        unionSets(a, b);
    }

    // number of queries
    int q;
    cin >> q;
    while (q--) {

        cin >> a;

        // to tell the parent(set ID) of element a
        cout << findSet(a) << endl;
    }

}
