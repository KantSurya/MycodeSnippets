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
vector<int>arr;
// ---------------------------------------------------------------------------
void init(){}
// int merge(vector<int>&arr, int l1,int r1,int l2,int r2){
int merge(int l1,int r1,int l2,int r2){
    // if(l1>r1 || l2>r2 || r1>l2)return 0;
    int n1 = r1-l1+1;
    int n2 = r2-l2+1;
    int start = l1,end = r2;
    vi temp(n1+n2);
    int ans = 0;
    int ind = 0;
    while(l1<=r1 && l2<=r2){
        if(arr[l1]>arr[l2]){
            ans+=(r1-l1+1);
            temp[ind++] = arr[l2++];
        }
        else {
            temp[ind++] = arr[l1++];
        }
    }
    while(l1<=r1)temp[ind++]=arr[l1++];
    while(l2<=r2)temp[ind++]=arr[l2++];
    ind = 0;
    // DEBUG(temp);
    for(int i=start;i<=end;++i)arr[i] = temp[ind++];
    return ans;
}
int mergeSort(int l,int r){
    if(l==r)return 0;
    if(r<l)return 0;
    int mid = (l+r)/2;
    int inv1 = mergeSort(l,mid);
    int inv2 = mergeSort(mid+1,r);
    return inv1 + inv2 + merge(l,mid,mid+1,r);
}

int getInvCount(vi arr, int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
 
    return inv_count;
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
    // cout<<"Case #"<<tc<<": ";
    int n;cin>>n;
    arr = vi (n);
    fi(0,n-1)cin>>arr[i];
    cout<<getInvCount(arr,n)<<endl;
    int invCount = mergeSort(0,n-1);
    cout<<invCount<<endl;
    // DEBUG(arr);
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