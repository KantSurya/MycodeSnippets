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
#define DEBUG(a...) cout<<#a<<": ";for(auto &it:a)cout<<it<<" ";cout<<"\n";
#define debug(a)cout<<#a<<": "<<a<<"\n";
// #define int long long

// ---------------------------------------------------------------------------
const int mod = 1e9+7;
const int maxn = 2e5 + 9;
// ---------------------------------------------------------------------------

const int maxSieve = 1e6+9;
vector<bool>isPrime(maxSieve,1);
vector<int>primes;

void sieve(){
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2;i*i<maxSieve;++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i;j<maxSieve;j+=i){
                isPrime[j]=0;
            }
        }
    }
}

// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    sieve();
    fi(0,20)cout<<primes[i]<<" ";
}

int32_t main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}	