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
void init(){}
vector<int>getNGR(vector<int>&heights){
    int n = heights.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;--i){
        ans[i]=n;
        while(!st.empty() && heights[st.top()]<=heights[i])st.pop();
        if(!st.empty())ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
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