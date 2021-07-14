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
#define int long long

// ---------------------------------------------------------------------------
const int mod = 1e9+7;
const int maxn = 2e5 + 9;
string text,pattern;
// ---------------------------------------------------------------------------
void init(){}

vector<int>getZ(string& s){
  int n = s.size();
  vector<int>Z(n);
  Z[0] = 0;
  int left = 0 , right = 0;
  for(int i = 1 ; i < n ; ++i){
    if(i>right){
      left = right = i;
      while(s[right-left]==s[right])right++;
      right--;
      Z[i] = (right-left+1);
    }
    else{
      int k = i-left;
      if(Z[k] + i <= right){
        Z[i] = Z[k];
      }
      else{
        left = i;
        while(right<n && s[right-left]==s[right])right++;
        right--;
        Z[i] = (right-left+1);
      }
    }
  }
  return Z;
}

void count(){
  string s = pattern + "#" + text;
  vector<int>Z = getZ(s);
  int ans = 0 ; 
  int m = pattern.size();
  for(int i = m+1;i<s.size();++i){
    if(Z[i]==m)ans++;
  }
  cout<<ans;
}

// ---------------------------------------------------------------------------
void test_case(int tc)
{
  // cout<<"Case #"<<tc<<": ";
  cin>>text>>pattern;
  count();
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