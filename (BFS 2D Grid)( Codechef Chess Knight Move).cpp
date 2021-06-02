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
#define print2d(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<"\n";}
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;
char ar[31][31];
bool vis[31][31];
int dist[31][31];
int dx[] = {-2,-1,1,2,2,1, -1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int N;
 
bool isValid(int x , int y)
{
	if(x > 8 || x < 1 || y > 8 || y < 1) return false;
	
	if(vis[x][y] ) return false;
	
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
		
		for(int i=0;i<8;i++)
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
{int srcX , srcY , endX , endY;
	
	int t;
	cin>>t;
	while(t--){
	    string s,t;
	    cin>>s>>t;
	    
	    for(int i=1;i<=8;i++){
	        for(int j=1;j<=8;j++){
	            vis[i][j]=0;
	        }
	    }
	    
	    srcX=s.at(0)-96;
	   
	    srcY=s.at(1)-48;
	    
	    endX=t.at(0)-96;
	 
	    endY=t.at(1)-48;
	    
	    
	    bfs(srcX,srcY);
	    
	    cout<<dist[endX][endY]<<endl;
	    
	}
	
}
