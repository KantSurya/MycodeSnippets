/*
    Author : SuryaKant
    Date : 28-05-2020
    Segment Tree, Lazy progragation, Range Sum Query
    
    Problem Statement : https://www.spoj.com/problems/HORRIBLE/
    Tutorial : https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/
 */



#include<bits/stdc++.h>
using namespace std;
 
long long ST[5000000];
long long lazy[5000000];
 
void update_range(long long node,long long start,long long end,long long l,long long r,long long  val)
{
    if(lazy[node]!=0)
    {
        ST[node]+=(end-start+1)*lazy[node];
 
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
 
    if(start>end || start>r || end<l)
        return;

    if(start>=l && end<=r)
    {
        ST[node]+=(end-start+1)*(val);
 
        if(start!=end)
        {
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
 
    long long  mid=(start+end)/2;
 
    update_range(node*2,start,mid,l,r,val);
    update_range(node*2+1,mid+1,end,l,r,val);
 
    ST[node]=ST[node*2]+ST[node*2+1];
}
 
long long getsum(long long  node,long long start,long long end,long long l,long long  r)
{
    if(lazy[node]!=0)
    {
        ST[node]+=(end-start+1)*lazy[node];
 
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
 
    if((start>=l && end<=r))
    {
        return ST[node];
    }
 
    if(start>end || start>r || end<l)
        return 0;
 
    int mid=(start+end)/2;
 
    long long sum_left=getsum(node*2,start,mid,l,r);
    long long sum_right=getsum(node*2+1,mid+1,end,l,r);
 
    return sum_left+sum_right;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        long long q;
        cin>>n>>q;

        memset(ST,0,sizeof(ST));
        memset(lazy,0,sizeof(lazy));
        while(q--)
        {
            long long x;
            cin>>x;
            long long  l,r;
            cin>>l>>r;
            if(x==1)
            {
                cout<<getsum(1,1,n,l,r)<<"\n";
            }
            else
            {
                long long val;
                cin>>val;
                update_range(1,1,n,l,r,val);
            }
        }
    }
} 
