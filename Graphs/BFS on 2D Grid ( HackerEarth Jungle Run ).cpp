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
char ar[31][31];
bool vis[31][31];
int dist[31][31];
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
int N;
 
bool isValid(int x , int y)
{
	if(x > N || x < 1 || y > N || y < 1) return false;
	
	if(vis[x][y] || ar[x][y] == 'T') return false;
	
	return true;
}
 
void bfs(int srcX , int srcY)
{
	queue< pair<int,int> > q;
	q.push( {srcX , srcY} );
	dist[srcX][srcY] = 0;
	vis[srcX][srcY] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];
			
			if(isValid(newX , newY))
			{
				dist[newX][newY] = d + 1;
				vis[newX][newY] = 1;
				q.push( {newX , newY} );
			}
		}
	}
	
}
 
int main()
{
	int srcX , srcY , endX , endY;
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>ar[i][j];
			if(ar[i][j] == 'S') srcX = i , srcY = j;
			if(ar[i][j] == 'E') endX = i , endY = j;
		}
	}
	
	bfs(srcX , srcY);
	cout<<dist[endX][endY];
}
