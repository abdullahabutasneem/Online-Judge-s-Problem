//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/

#include<bits/stdc++.h>
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long lll;
typedef long long ll;
#define all(x) x.begin(),x.end()
const long long MOD = 1000000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define pf printf
#define sf(x) scanf("%d",&x);
#define sff(x,y) scanf("%d%d",&x,&y);
#define sfff(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define sfl(x) scanf("%lld",&x);
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define np std::string::npos
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<n;i++)
#define fof(i,a,b) for(int i=a;i<=b;i++)
#define off(i,a,b) for(int i=a;i>=b;i--)
#define of(i,n) for(int i=n-1;i>=0;i--)
#define stl(i,x) for(auto i=x.begin(); i!=x.end();i++)
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cases(t) printf("Case %d:",t)
#define PI acos(-1)
#define findv(val) find(all(v),val)
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))

int knigtx8[] = {2, 2, -2, -2, 1, 1, -1, -1}; ///knight move in chess
int knigty8[] = {1, -1, 1, -1, 2, -2, 2, -2}; ///knight move in chess
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; ///for 8 directions
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1}; ///for 8 directions
int dx4[] = {0, 0, 1, -1}; ///for 4 directions
int dy4[] = {1, -1, 0, 0}; ///for 4 directions
const int maxx=100005;

//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
void file()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
ll pw(ll a, ll b)
{
    ll ans = 1;
    for(ll i = 1; i <= b; ++i)
        ans = (ans * a);
    return ans;
}
template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}

int main()
{
    //file();
    IOS;
    int store[26];

    fo(i,26){
    	if(i==0 or i==4 or i==7 or i==8 or i==14 or i==20 or i==22 or i==24){
    		store[i]=-1;
    	}
    	else if(i==17)store[i]=6;
    	else if(i==12 or i==13)store[i]=5;
    	else if(i==11)store[i]=4;
    	else if(i==3 or i==19)store[i]=3;
    	else if(i==1 or i==5 or i==15 or i==21)store[i]=1;
    	else store[i]=2;
    }
    // fo(i,26)cout<<store[i]<<" ";
    // cout<<endl;
    string s;
    while(cin>>s)
    {
    	map<int,bool>exist;
    	vector<int>v;
    	int n=s.size();
    	if(n==1){
    		if(store[s[0]-'A']!=-1)cout<<store[s[0]-'A']<<endl;
    		else cout<<endl;
    		continue;
    	}
    	for(int i=0;i<n; ){
    		//int k= (s[i]-'A');
    		int j;
    		bool ok=0;
    		//cout<<k<<" "<<store[k]<<endl;
    		for(j=i+1;j<n;j++){
    			int now = s[j]-'A';
    			int prev = s[j-1]-'A';
    			//cout<<"dekho = "<<s[j-1]<<" "<<s[j]<<endl;
    			if(store[now]==store[prev]){
    				if(j==n-1){
    					if(store[now]!=-1){
    						v.pb(store[now]);
    					}
    					ok=1;
    				}
    				else continue;
    			}
    			else{
                   // cout<<"check PREV = "<<store[prev]<<endl;
                    //cout<<"check NOW = "<<store[now]<<endl;
    				if(j-i>1 and store[prev]!=-1){
    					v.pb(store[prev]);
    				}
    				else if(store[prev]!=-1){
    					v.pb(store[prev]);
    				}

    				if(j==n-1){
    					if(store[now]!=-1){
    						v.pb(store[now]);
    					}
    					ok=1;
    				}
    				else{
    					i=j;
    					break;
    				}
    			}
    		}
    		if(ok)break;
    	}
    	if(v.size()==0)cout<<endl;
	    else{
	    	fo(i,v.size())cout<<v[i];
	    	cout<<endl;
	    }
    }
    return 0;
}

///Alhamdulillah
//Bismillahir Rahmanir Rahim
/*
    Abdullah Abu Tasneem
    Dept of CSTE, NSTU
*/

#include<bits/stdc++.h>
//for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
//template <typename T>using ordered_set =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long lll;
typedef long long ll;
#define all(x) x.begin(),x.end()
const long long MOD = 1000000007;
#define fil(x) memset(x, 0, sizeof(x))
#define fillb(x) memset(x,false,sizeof(x))
#define fillm(x) memset(x, -1, sizeof(x))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define pf printf
#define sf(x) scanf("%d",&x);
#define sff(x,y) scanf("%d%d",&x,&y);
#define sfff(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define sfl(x) scanf("%lld",&x);
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define np std::string::npos
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<n;i++)
#define fof(i,a,b) for(int i=a;i<=b;i++)
#define off(i,a,b) for(int i=a;i>=b;i--)
#define of(i,n) for(int i=n-1;i>=0;i--)
#define stl(i,x) for(auto i=x.begin(); i!=x.end();i++)
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define cases(t) printf("Case %d:",t)
#define PI acos(-1)
#define findv(val) find(all(v),val)
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))

int knigtx8[] = {2, 2, -2, -2, 1, 1, -1, -1}; ///knight move in chess
int knigty8[] = {1, -1, 1, -1, 2, -2, 2, -2}; ///knight move in chess
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; ///for 8 directions
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1}; ///for 8 directions
int dx4[] = {0, 0, 1, -1}; ///for 4 directions
int dy4[] = {1, -1, 0, 0}; ///for 4 directions
const int maxx=100005;

//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
void file()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
ll pw(ll a, ll b)
{
    ll ans = 1;
    for(ll i = 1; i <= b; ++i)
        ans = (ans * a);
    return ans;
}
template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}

int main()
{
    file();
    IOS;
    int store[26];

    fo(i,26){
    	if(i==0 or i==4 or i==7 or i==8 or i==14 or i==20 or i==22 or i==24){
    		store[i]=-1;
    	}
    	else if(i==17)store[i]=6;
    	else if(i==12 or i==13)store[i]=5;
    	else if(i==11)store[i]=4;
    	else if(i==3 or i==19)store[i]=3;
    	else if(i==1 or i==5 or i==15 or i==21)store[i]=1;
    	else store[i]=2;
    }
    // fo(i,26)cout<<store[i]<<" ";
    // cout<<endl;
    string s;
    while(cin>>s)
    {
    	map<int,bool>exist;
    	vector<int>v;
    	int n=s.size();
    	if(n==1){
    		if(store[s[0]-'A']!=-1)cout<<store[s[0]-'A']<<endl;
    		else cout<<endl;
    		continue;
    	}
    	for(int i=0;i<n; ){
    		//int k= (s[i]-'A');
    		int j;
    		bool ok=0;
    		//cout<<k<<" "<<store[k]<<endl;
    		for(j=i+1;j<n;j++){
    			int now = s[j]-'A';
    			int prev = s[j-1]-'A';
    			//cout<<"dekho = "<<s[j-1]<<" "<<s[j]<<endl;
    			if(store[now]==store[prev]){
    				if(j==n-1){
    					if(store[now]!=-1){
    						v.pb(store[now]);
    					}
    					ok=1;
    				}
    				else continue;
    			}
    			else{
                   // cout<<"check PREV = "<<store[prev]<<endl;
                    //cout<<"check NOW = "<<store[now]<<endl;
    				if(j-i>1 and store[prev]!=-1){
    					v.pb(store[prev]);
    				}
    				else if(store[prev]!=-1){
    					v.pb(store[prev]);
    				}

    				if(j==n-1){
    					if(store[now]!=-1){
    						v.pb(store[now]);
    					}
    					ok=1;
    				}
    				else{
    					i=j;
    					break;
    				}
    			}
    		}
    		if(ok)break;
    	}
    	if(v.size()==0)cout<<endl;
	    else{
	    	fo(i,v.size())cout<<v[i];
	    	cout<<endl;
	    }
    }
    return 0;
}

///Alhamdulillah
