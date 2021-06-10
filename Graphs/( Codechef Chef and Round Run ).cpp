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
vi ar[1000001];
vi tr[1000001];

vi order;
vi SCC;

int vis[1000001];

int arr[1000001];

void dfs(int node)
{
	vis[node] = 1;
	
	for(int child : ar[node])
	if(vis[child] == 0)
	dfs(child);
	
	order.pb(node);
}

void dfs1(int node)
{
	vis[node] = 1;
	
	for(int child : tr[node])
	if(vis[child] == 0)
	dfs1(child);
	
	SCC.pb(node);
}

int ans;

int main()
{
	int n , a , b , m , t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		REP(i , n) ar[i-1].clear() , tr[i-1].clear() , vis[i-1] = 0;
		
		order.clear();
		
		for(int i=0;i<n;i++)
		cin>>arr[i];
		
		REP(i , n)
		{
		    b=(i-1 + arr[i-1] + 1)%n;
			
			ar[i-1].pb(b);
			tr[b].pb(i-1);
		}
		
		REP(i , n)
		if(vis[i-1] == 0) dfs(i-1);
		
		REP(i , n) vis[i-1] = 0;
		
		reverse(order.begin(),order.end());
		ans=0;
		
		for(auto i:order)
		if(vis[i] == 0)
		{
			SCC.clear();
			dfs1(i);
			
			
			if(SCC.size()>=2){
			    ans+=SCC.size();
			}
			else{
			    
			    int ele=SCC[0];
			   
			   if((ele + arr[ele] +1 )%n==ele){
			       ans++;
			   }
			    
			}
			
			
		}
		
		cout<<ans<<endl;
	}
}


