#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define endl "\n";

vector<int>adj[100001];
bool vis[100001];
int parent[100001];
int sv,ev;
bool dfs(int u, int par)
{
    vis[u] = 1;
    parent[u] = par;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(v==par)continue;
        if(vis[v]){
            sv = v;
            ev = u;
            return 1;
        }
        if(!vis[v]){
            if(dfs(v,u))return 1;
        }
    }
    return 0;
}

void output(vector<int>ans)
{
    int tv = ev;
    ans.push_back(ev);
    while(tv!=sv){
        ans.push_back(parent[tv]);
        tv = parent[tv];
    }
    ans.push_back(ev);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    vector<int>ans;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok=0;
    for(int i=1;i<=n;i++){
        if(!vis[i] and dfs(i,-1)){
            output(ans);
            ok=1;
            break;
        }
    }
    if(!ok)cout<<"IMPOSSIBLE"<<endl;

    return 0;
}

///Alhamdulillah

