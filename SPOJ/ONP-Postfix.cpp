/*
      Author : surya_kant
      Created : 10-06-2020 (1252)
      
      Stack,Infix to postfix conversion, COnventional
      
      Problem Statement : https://www.spoj.com/problems/ONP/
 */

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define deb(name,value) cout <<"->>  "<<name<< "= " <<value<<" "
#define frepi(a,b,k) for(long long i=a;i<=b;i+=k)
#define frepj(a,b,k) for(long long j=a;j<=b;j+=k)
#define fperi(a,b,k) for(long long i=a;i>=b;i-=k)
#define fperj(a,b,k) for(long long j=a;j>=b;j-=k)
#define infile    freopen("/home/suryakant/input.txt","r",stdin)
#define outfile   freopen("/home/suryakant/output.txt","w",stdout)

int prior(char c)
{
	if(c=='+')return 1;
	if(c=='-')return 2;
	if(c=='*')return 3;
	if(c=='/')return 4;
	if(c=='^')return 5;
}
void solve()
{
    string s;cin>>s;
    string ans="";
    stack<char>st;
    int n = s.size();
    for(int i=0;i<n;++i)
    {
    	if(s[i]>='a' && s[i]<='z')
    	{
    		ans+=s[i];
    		continue;
    	}
    	if(s[i]=='(')
    	{
    		st.push('(');
    		continue;
    	}
    	if(s[i]==')')
    	{
    		while(st.top()!='(')
    		{
    			ans+=st.top();
    			st.pop();
    		}
    		st.pop();
    		continue;
    	}
    	if(st.empty())
    	while(prior(st.top())>prior(s[i]) && !st.empty())
    	{
    		ans+=st.top();
    		st.pop();
    	}
    	st.push(s[i]);
    }
    while(!st.empty())
    {
    	ans+=st.top();
    	st.pop();
    }
    cout<<ans<<"\n";
}

int main()
{
    // infile,outfile;
    long long t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
}
