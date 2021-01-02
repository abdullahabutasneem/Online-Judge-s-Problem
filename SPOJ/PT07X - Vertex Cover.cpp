//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/

// Minimum Vertex Cover (DP)
// Reference: http://www.shafaetsplanet.com/planetcoding/?p=582

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fillm(x) memset(x, -1, sizeof(x))
#define vi vector<int>
#define pf printf
#define sf(x) scanf("%d",&x);
#define sff(x,y) scanf("%d%d",&x,&y);
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define fof(i,a,b) for(int i=a;i<=b;i++)

void file()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

#define N 100005
vi edge[N];
int par[N];
int dp[N][3];

int find(int u, int guard)
{
	if(edge[u].size()==0)return 0;
	if(dp[u][guard] != -1)return dp[u][guard];
	int sum=0;
	fo(i,edge[u].size()){
		int v = edge[u][i];
		if(v!=par[u]){
			par[v] = u;
			if(guard==0)sum += find(v,1);
			else sum += min(find(v,1),find(v,0));
		}
	}
	return dp[u][guard] = sum + guard;
}

int main()
{
    file();
    IOS;
    int n;sf(n);
    fo(i,n-1){
    	int u,v;
    	sff(u,v);
    	edge[u].pb(v);
    	edge[v].pb(u);
    }
    fillm(dp);
    int ans = min(find(1,0), find(1,1));
    pf("%d\n",ans);
    return 0;
}

///Alhamdulillah
