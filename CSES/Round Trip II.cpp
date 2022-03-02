#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define endl "\n";

vector<int>adj[100001];
bool vis[100001];
stack<int>pathStack;
bool stackFlag[100001];
bool dfs(int u)
{
    vis[u] = 1;
    pathStack.push(u);
    stackFlag[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[v]){
            if(dfs(v))return 1;
        }
        if(stackFlag[v]){
            pathStack.push(v);
            return 1;
        }
    }
    pathStack.pop();
    stackFlag[u]=0;
    return 0;
}

int main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool ok=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i)){
                ok=1;
                break;
            }
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE"<<endl;return 0;
    }

    vector<int>ans;
    int topp = pathStack.top();
    while(pathStack.size()!=0){
        int temp = pathStack.top();
        ans.push_back(temp);
        if(temp==topp and ans.size()!=1)break;
        pathStack.pop();
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}

///Alhamdulillah

