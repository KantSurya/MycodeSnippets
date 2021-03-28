/*
    Author : SuryaKant
    Date : 29-05-2020
    
    Segment Trees, Easy, Minimum Range query
    Problem Statement : https://www.spoj.com/problems/RPLN/
 */

#include<bits/stdc++.h>
using namespace std;
 
int arr[1000009];
int st[4000009];
 
void create(int node,int start,int end)
{
    if(start==end)
    {
        st[node]=arr[start];
        return;
    }
 
    int mid=( (start+end)>>1);
 
    create(node*2,start,mid);
    create(node*2+1,mid+1,end);
 
    st[node]=min(st[node*2],st[node*2+1]);
}
 
int query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
        return INT_MAX;
    if(start>=l && end<=r)
        return st[node];
    int mid=( (start+end)>>1);
 
    int q1=query(node*2,start,mid,l,r);
    int q2=query(node*2+1,mid+1,end,l,r);
 
    return min(q1,q2);
}
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;++j)
    {
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;++i)
            cin>>arr[i];
        create(1,1,n);
        cout<<"Scenario #"<<j<<":\n";
        for(int i=1;i<=q;++i)
        {
            int l,r;
            cin>>l>>r;
            int x=min(l,r);
            int y=max(l,r);
            cout<<query(1,1,n,x,y)<<"\n";
        }
 
    }
} 
