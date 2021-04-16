// https://www.spoj.com/problems/RPLN/
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
int n,q;
vi st,arr;
// ---------------------------------------------------------------------------
void init(){
    st = vi (2*n+1);
    arr = vi(n+1);
}

// ---------------------------------------------------------------------------
void build(int node,int start,int end){
    if(start==end){
        st[node] = arr[start];
    }
    else{
        int mid = start + (end-start)/2;
        build(node+1,start,mid);
        build(node+2*(mid-start+1),mid+1,end);
        st[node] = min(st[node+1],st[node+2*(mid-start+1)]);
    }
}
int query(int node,int start,int end,int ql,int qr){

    if(ql>end || qr<start)return 1e18;
    if(ql<=start && end<=qr)return st[node];
    int mid = start + (end-start)/2;

    if(qr<=mid)return query(node+1,start,mid,ql,qr);
    else if(ql>mid)return query(node+2*(mid-start+1),mid+1,end,ql,qr);

    int leftQuery = query(node+1,start,mid,ql,qr);
    int rightQuery = query(node+2*(mid-start+1),mid+1,end,ql,qr);

    return min(leftQuery,rightQuery);
}
// ---------------------------------------------------------------------------



// ---------------------------------------------------------------------------
void test_case(int tc)
{
    cout<<"Scenario #"<<tc<<":\n";
    cin>>n>>q;
    init();
    fi(1,n)cin>>arr[i];
    build(1,1,n);
    while(q--){
        int u,v;cin>>u>>v;
        cout<<query(1,1,n,u,v)<<"\n";
    }
}
 
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