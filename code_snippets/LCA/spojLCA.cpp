#include<bits/stdc++.h>
using namespace std;
// --------------------------------------------------------------------------------------------------
#define FASTIO	            ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll                  long long 
#define mset(A,val)         memset(A,val,sizeof(A))
#define fi(a,b)             for(int i=a;i<=b;++i)
#define fj(a,b)             for(int j=a;j<=b;++j)
#define all(x)              x.begin(),x.end()
#define vi                  vector<int>
#define pii                 pair<int,int>
#define pb                  push_back
#define eb                  emplace_back
#define DEBUG(a...)         cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<endl;
#define debug(a)            cout<<#a<<": "<<a<<"\n";
#define hola                cout<<"hola"<<endl;
#define int                 long long
// --------------------------------------------------------------------------------------------------
const int mod = 1e9+7;
const int maxn = 2e5 + 9;
int n;
int hMax;
vector<vector<int>>graph;
vector<vector<int>>up;
vector<int>depth;
vector<bool>vis;
// --------------------------------------------------------------------------------------------------
void init(){
    hMax = 0;
    while((1<<hMax)<=n)hMax++;
    graph = vector<vector<int>>(n+1);
    up = vector<vector<int>>(n+1,vector<int>(hMax,0));
    vis = vector<bool>(n+1,0);
    depth = vector<int>(n+1,0);
}

void dfs(int node){
    vis[node] = true;
    for(auto & child : graph[node]){
        if(!vis[child]){
            up[child][0] = node;
            for(int j = 1 ; j < hMax ; ++j){
                up[child][j] = up[up[child][j-1]][j-1];
            }
            depth[child] = depth[node] + 1;
            dfs(child);
        }
    }
}

int getKthAncestor(int node, int k) {
    if(depth[node]<k)return -1;
    for(int j = 0 ; j < hMax ; ++j){
        if( k & (1<<j) ){
            node = up[node][j];
        }
    }
    return node;
}

int get_lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i = 0 ; i < hMax; ++i){
        if(diff&(1<<i)){
            u = up[u][i];
        }
    }
    if(u==v)return u;
    // it is necessary to go decreasingly from : hMax - 1 to 0 
    for(int j = hMax - 1 ; j>=0 ; --j){
        if(up[u][j]!=up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

// --------------------------------------------------------------------------------------------------
void test_case(int tc)
{
    cout<<"Case "<<tc<<": "<<endl;
    cin>>n;
    init();
    fi(1,n){
        int m;cin>>m;
        while(m--){
            int v;cin>>v;
            graph[i].push_back(v);
            graph[v].push_back(i);
        }
    }
    dfs(1);
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        cout<<get_lca(u,v)<<endl;
    }
}
// --------------------------------------------------------------------------------------------------
int32_t main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         // freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}	