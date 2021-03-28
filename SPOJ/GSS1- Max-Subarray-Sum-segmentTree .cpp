/*
    Date : 30-05-2020
    Given range [l,r] return maximum subarray sum
    Problem Statement : https://www.spoj.com/problems/GSS1/
    
    Tutorial(s) : http://e-maxx.ru/algo/segment_tree // Search for a subsegment with a maximum sum
                  https://spojsolutionsgss1.blogspot.com/2020/03/pre.html
 */

#include<bits/stdc++.h>
using namespace std;
class st
{
    public:
        long long sum;
        long long pre;
        long long suff;
        long long ans;
    void init(long long x)
    {
        sum=pre=suff=ans=x;
    }
};

st combine(st a,st b)
{
    st new_s;
    new_s.sum=a.sum+b.sum;
    new_s.pre= max(a.pre,(a.sum+b.pre));
    new_s.suff=max(b.suff,(a.suff+b.sum));
    new_s.ans=max(max(a.ans,b.ans),(a.suff+b.pre));
    return new_s;
}

int arr[100009];
st ST[400009];

void create(int node,int start,int end)
{
    if(start==end)
    {
        ST[node].init(arr[start]);
        return;
    }

    int mid=( (start+end)>>1 );

    create(node*2,start,mid);
    create(node*2+1,mid+1,end);

    ST[node]=combine(ST[node*2],ST[node*2+1]);
}

st query(int node,int start,int end,int l,int r)
{
    // if(start>r || end<l)
    //     return ST[1];
    if(start>=l && end<=r)
    {
        return ST[node];
    }

    int mid=( (start+end)>>1);

    if(r<=mid)
        return query(node*2,start,mid,l,r);
    if(l>mid)
        return query(node*2+1,mid+1,end,l,r);

    return combine(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    create(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;

        st temp=query(1,1,n,l,r);
        cout<<temp.ans<<"\n";
    }
}
