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
int cnt = 0;
// ---------------------------------------------------------------------------
void init(){}
void permute(vi arr,int l,int r){
    if(l==r){
        // permutation generated
        DEBUG(arr);
        cnt++;
        return;
    }
    for(int i=l;i<=r;++i){
        swap(arr[l],arr[i]);
        permute(arr,l+1,r);
        swap(arr[l],arr[i]);
    }
}

// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    int n = 3;
    vi arr(n);
    iota(all(arr),0);
    permute(arr,0,n-1);
    cout<<cnt<<"\n";
    init();
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