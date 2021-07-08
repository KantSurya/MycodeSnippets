#include<bits/stdc++.h>
using namespace std;

#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(A,val) memset(A,val,sizeof(A))
#define fi(a,b) for(int i=a;i<=b;++i)
#define fj(a,b) for(int j=a;j<=b;++j)
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define DEBUG(a...) cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<"\n";
#define debug(a)cout<<#a<<": "<<a<<"\n";
#define int long long

// ---------------------------------------------------------------------------
const int mod = 1e9+7;
const int maxn = 2e5 + 9;

// ---------------------------------------------------------------------------
int n;
vector<vi>graph,parent;
int hMax;
int timer;
vi tin,tout;

void init(){
    graph = vector<vi>(n+1);
    hMax = log2(n)+1;
    parent = vector<vi>(n+1,vector<int>(hMax+1,n));
    timer = 0;
    tin = vi(n+1,-1);
    tout = vi(n+1,-1);
}


void dfs(int node,int par){
    tin[node] = ++timer;
    parent[node][0]=par;
    for(int i=1;i<=hMax;++i){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }
    for(auto & child : graph[node]){
        if(tin[child]==-1)dfs(child,node);
    }
    tout[node] = ++timer;
}


bool isAncestor(int u,int v){
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}


int getLCA(int u,int v){
    if(isAncestor(u,v))return u;
    if(isAncestor(v,u))return v;
    for(int j=hMax;j>=0;--j){
        if(!isAncestor(parent[u][j],v)){
            u = parent[u][j];
        }
    }
    return parent[u][0];
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    init();
    cout<<"hola"<<endl;
}

int32_t main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         // freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}