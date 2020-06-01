/*
  Author : surya_kant
  Created : 01-06-2020 (2339)
  
  Segment Trees, Lazy Propagation, Important, Count primes in [l,r], Update [l,r] to v 
  Problem Statement : https://www.spoj.com/problems/CNTPRIME/
*/

// 2300
#include<bits/stdc++.h>
using namespace std;

int arr[10009];
int st[40009];
int lazy[40009];
int prime[1000009];

void build(int node,int start,int end)
{
    if(start==end)
    {
        if(prime[arr[start]]==0)
            st[node]=1;
        else
            st[node]=0;
        return;
    }

    int mid = ((start+end)>>1);
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    st[node] = st[node*2] + st[node*2+1];
}

void update(int node,int start,int end,int l,int r,int val)
{
    if(lazy[node]!=-1)
    {
        int num = lazy[node];

        if(prime[num]==0)
            st[node] = (end-start+1);
        else
            st[node] = 0;
        if(start!=end)
        {
            lazy[node*2]=num;
            lazy[node*2+1]=num;
        }
        lazy[node]=-1;
    }

    if(end<l || start>r)
        return;
    if(start>=l && end<=r)
    {
        int num = val;

        if(prime[num]==0)
            st[node] = (end-start+1);
        else
            st[node] = 0;
        if(start!=end)
        {
            lazy[node*2]=num;
            lazy[node*2+1]=num;
        }
        return;
    }

    int mid = ((start+end)>>1);

    update(node*2,start,mid,l,r,val);
    update(node*2+1,mid+1,end,l,r,val);

    st[node] = st[node*2] + st[node*2+1];
}

int query(int node,int start,int end,int l,int r)
{
    if(lazy[node]!=-1)
    {
        int num = lazy[node];

        if(prime[num]==0)
            st[node] = (end-start+1);
        else
            st[node] = 0;
        if(start!=end)
        {
            lazy[node*2]=num;
            lazy[node*2+1]=num;
        }
        lazy[node]=-1;
    }

    if(end<l || start>r)
        return 0;

    if(start>=l && end<=r)
    {
        return st[node];
    }

    int mid = ((start+end)>>1);

    return query(node*2,start,mid,l,r) + query(node*2+1,mid+1,end,l,r);
}

int main()
{
    // memset(lazy,-1,sizeof(lazy));    // Mistake : lazy should be updated after each query case
    memset(prime,0,sizeof(prime));
    for(int i=2;i*i<1000009;++i)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<1000009;j+=i)
                prime[j]=1;
        }
    }
    prime[0]=prime[1]=1;
    int t;cin>>t;
    for(int j=1;j<=t;++j)
    {
        memset(lazy,-1,sizeof(lazy));
        cout<<"Case "<<j<<":\n";
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;++i)
            cin>>arr[i];
        build(1,1,n);
        while(q--)
        {
            int type,l,r;
            cin>>type>>l>>r;

            if(type==0)
            {
                int v;cin>>v;

                update(1,1,n,l,r,v);
            }
            else
            {
                cout<<query(1,1,n,l,r)<<"\n";
            }
        }
    }

}
