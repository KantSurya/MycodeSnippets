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
int n;
vector<vector<pii>>graph;
// ---------------------------------------------------------------------------
void init(){
    graph = vector<vector<pii>>(n+1);
}
void dijkstra(int a){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1,1e18);
    dist[a]=0;
    pq.push({dist[a],a});

    while(!pq.empty()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if(du!=dist[u])continue;
        for(auto & x : graph[u]){
            int v = x.first;
            int cst = x.second;
            if(dist[v]>dist[u]+cst){
                dist[v] = dist[u]+cst;
                pq.push({dist[v],v});
            }
        }
    }
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    int e;
    cin>>n>>e;
    init();
    fi(1,e){
        int u,v,cst;cin>>u>>v>>cst;
        graph[u].push_back({v,cst});
    }
    dijkstra(a);
}

int32_t main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         // freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}	