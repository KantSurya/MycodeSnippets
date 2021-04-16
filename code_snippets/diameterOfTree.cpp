// https://codeforces.com/gym/102694/problem/A

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
#define pb push_back
#define eb emplace_back
#define DEBUG(a...) cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<endl;
#define debug(a)cout<<#a<<": "<<a<<"\n";
#define hola cout<<"hola"<<endl;
// #define int long long
// ---------------------------------------------------------------------------
const int mod = 1e9+7;
const int maxn = 2e5 + 9;
int n;
vector<vi>graph;
vector<bool>vis;

// ---------------------------------------------------------------------------
void init(){
    graph = vector<vi>(n+1);
    vis = vector<bool>(n+1,0);
}
int bfs(int src,bool ok){
    vi dist(n+1);
    vis = vector<bool>(n+1,0);
    int maxDistance = 0;
    int maxDistanceNode = 1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto & x : graph[u]){
            if(!vis[x]){
                dist[x] = dist[u]+1;
                if(dist[x]>maxDistance){
                    maxDistance = dist[x];
                    maxDistanceNode = x;
                }
                vis[x]=true;
                q.push(x);
            }
        }
    }
    if(ok)return maxDistanceNode;
    else return maxDistance;
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    cin>>n;
    init();
    fi(1,n-1){
        int u,v;cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int diameter = bfs(bfs(1,1),0);
    cout<<3*diameter;
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