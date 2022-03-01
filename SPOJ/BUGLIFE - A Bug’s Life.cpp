#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10005];
bool vis[10005];
int col[10005];
bool dfs(int u, int c){
    vis[u]=1;
    col[u]=c;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[v]){
            if(dfs(v,c^1)==false)return false;
        }
        else{
            if(col[v]==col[u])return false;
        }
    }
    return true;
}
int main()
{
    int t;cin>>t;
    for(int test=1;test<=t;test++){
        int n,e;
        cin>>n>>e;

        for(int i=0;i<=n+2;i++){
            adj[i].clear();
            vis[i]=0;
        }

        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ok=1;
        cout<<"Scenario #"<<test<<":"<<endl;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!dfs(i,0)){
                    ok=0;break;
                }
            }
        }
        if(ok)cout<<"No suspicious bugs found!"<<endl;
        else cout<<"Suspicious bugs found!"<<endl;


    }
    return 0;
}

///Alhamdulillah

