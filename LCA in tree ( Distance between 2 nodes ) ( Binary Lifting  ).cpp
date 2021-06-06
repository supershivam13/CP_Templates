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
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// N is taken as 10^5
vector<int> ar[100001];

// maxN = log2(N)
int maxN;
int level[100001] , LCA[100001][maxN + 1];


// dfs to intialise the 2^0 parent of each node and store the levels of each node in level array
void dfs(int node , int lvl , int par)
{

    level[node] = lvl;

    // initialising the 2^0th ( one step above ) parent in the LCA Array
    LCA[node][0] = par;

    for (int child : ar[node])
        if (child != par)
        {
            dfs(child , lvl + 1 , node);
        }
}

// initial pre-computational part to calculate LCA
void init(int n)
{
    // one dfs call with root node
    dfs(1 , 0 , -1);

    // computing the LCA Array ( not starting from i=0 because ( 2^0 th parent ) is already
    // calculated by the DFS call above and using that result we are calculating the further LCA Array
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)




            if (LCA[j][i - 1] != -1)
            {
                // 2^i = 2^(i-1) * 2^1;
                int par = LCA[j][i - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
    }
}

int getLCA(int a , int b)
{
    // assuming b is deeper than a, if it is not then swap the values of a and b
    if (level[b] < level[a]) swap(a , b);

    // d is the difference of levels of given nodes
    int d = level[b] - level[a];


    while (d > 0)
    {
        // we are making a jump of 2^i levels
        int i = log2(d);
        b = LCA[b][i];

        // d - = ( 2^i )
        d -= 1 << i;
    }

    // till here, we have reached the same levels of given nodes
    // now if they are equal, then return either a or b as LCA
    if (a == b) return a;


    for (int i = maxN; i >= 0; i--)

        // to make sure that 2^i parent exists and we have not crossed the LCA in a jump of 2^i
        // (  LCA[a][i] != LCA[b][i] ensures that we have not crossed the LCA  )
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i] , b = LCA[b][i];
        }

    // after coming out of this loop, we have reached the position where the parent of a and parent of b
    // is same ( and also our final result ) and we can return either LCA[a][0] or LCA[b][0]

    return LCA[a][0];
}


int getDist(int a , int b)
{
    int lca = getLCA(a , b);

    // formula for distance between 2 nodes
    return level[a] + level[b] - 2 * level[lca];
}


int main()
{
    int n , a , b , q;

    cin >> n;

    maxN = log2(n);

    // initialising the LCA array with -1 initially
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxN; j++)
            LCA[i][j] = -1;
    }

    for (int i = 1; i < n; i++)
        cin >> a >> b , ar[a].pb(b) , ar[b].push_back(a);

    // pre-computational part to calculate LCA
    init(n);

    cin >> q;

    while (q--)
    {
        cin >> a >> b;
        cout << getDist(a , b) << endl;
    }
}
