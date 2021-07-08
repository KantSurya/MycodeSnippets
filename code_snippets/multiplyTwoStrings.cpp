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

// ---------------------------------------------------------------------------
void init(){}
string multiply(string s1,char x){
    int m = x-'0';
    string ans = "";
    reverse(s1.begin(),s1.end());
    int carry = 0;
    for(int i=0;i<s1.size();++i){
        int temp = carry + (s1[i]-'0')*(m);
        ans.push_back(temp%10+'0');
        carry = temp/10;
    }
    if(carry>0)ans.push_back(carry + '0');
    reverse(ans.begin(),ans.end());
    return ans;
}
string add(string s1,string s2){
    string ans = "";
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int carry = 0;
    if(s1.size()>s2.size())swap(s1,s2);
    for(int i=0;i<s1.size();++i){
        int temp = s1[i]-'0' + s2[i] -'0' + carry;
        ans.push_back(temp%10 + '0');
        carry = temp/10;
    }
    for(int i=s1.size();i<s2.size();++i){
        int temp = s2[i]-'0' + carry;
        ans.push_back(temp%10 + '0');
        carry = temp/10;
    }
    if(carry>0){
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string multiplyStrings(string s1, string s2) {
    //Your code here
    if(s1=="0" || s2=="0")return "0";
    int countNeg = ( (s1[0]=='-') + (s2[0]=='-'));
    if(s1[0]=='-')s1 = s1.substr(1,s1.size());
    if(s2[0]=='-')s2 = s2.substr(1,s2.size());
    if(s1.size()>s2.size())swap(s1,s2);
    reverse(s1.begin(),s1.end());
    string ans = multiply(s2,s1[0]);
    for(int i=1;i<s1.size();++i){
        string temp = multiply(s2,s1[i]);
        for(int j=0;j<i;++j)temp.push_back('0');
        ans = add(ans,temp);
    }
    int i = 0;
    while(i<ans.size() && ans[i]=='0')i++;
    ans = ans.substr(i,ans.size());
    if(countNeg==1)ans = "-" + ans;
    return ans;
}

string multiplyStringsShort(string s1, string s2) {
    if(s1=="0" || s2=="0")return "0";
    int countNeg = ( (s1[0]=='-') + (s2[0]=='-'));
    if(s1[0]=='-')s1 = s1.substr(1,s1.size());
    if(s2[0]=='-')s2 = s2.substr(1,s2.size());
    int m = s1.size(), n = s2.size();
    string ans(m + n, '0');
    for(int i = m - 1; i >= 0; --i){
        for(int j = n - 1; j >= 0; --j){
            int sum = (s1[i] - '0') * (s2[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = (sum % 10) + '0';
            ans[i + j] += (sum / 10);
        }
    }
    for(int i = 0; i < m + n; ++i){
        if(ans[i] != '0'){
            ans = ans.substr(i,m+n);
            if(countNeg==1)ans = "-" + ans;
            return ans;
        }
    }
    return "0";
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