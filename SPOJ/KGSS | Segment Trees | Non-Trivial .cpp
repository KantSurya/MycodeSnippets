/*
    Author : surya_kant
    Date : 01-06-2020 (2052)
    Segment Trees, Non Trivial, structure/class, Medium/Tough, KGSS - Maximum Sum, maximum sum of two elements

    Problem Statement : https://www.spoj.com/problems/KGSS/
    Another solution (on Internet) : https://github.com/Jaskamalkainth/Spoj/blob/master/kgss.cpp
    More Problems : https://jaskamalkainth.github.io/Segment-tree-Problems/
*/

#include<iostream>
using namespace std;
// 19:30
class tree
{
    public:
        int max1;
        int max2;
    void init(int x)
    {
        max1=x;
        max2=-999999;
    }
};

tree st[400009];
int arr[100009];

tree combine(tree a,tree b)
{
    tree temp;
    temp.max1=max(a.max1,b.max1);
    temp.max2=max(min(a.max1,b.max1),max(a.max2,b.max2));

    return temp;
}

void build(int node,int start,int end)
{
    if(start==end)
    {
        st[node].init(arr[start]);
        return;
    }

    int mid = ( (start+end)>>1 );
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    st[node] = combine(st[node*2],st[node*2+1]);
}

tree query(int node,int start,int end,int l,int r)
{   
    // if(start>r || end<l) // This will also work 
    // {
    //     st[0].init(-999999);
    //     return st[0];
    // }

    if(start>=l && end<=r)
        return st[node];

    int mid = ((start+end)>>1);

    if(l>mid)
        return query(node*2+1,mid+1,end,l,r);
    if(r<=mid)
        return query(node*2,start,mid,l,r);
    return combine(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
}

void update(int node,int start,int end,int index, int val)
{
    if(start>index || end<index)
        return;
    if(start==end)
    {
        st[node].init(val);
        return;
    }

    int mid = ((start+end)>>1);

    if(index>mid)
        update(node*2+1,mid+1,end,index,val);
    if(index<=mid)
        update(node*2,start,mid,index,val);

    st[node] = combine(st[node*2],st[node*2+1]);
}

int main()
{
    int n;cin>>n;

    for(int i=1;i<=n;++i)
        cin>>arr[i];
    build(1,1,n);

    int q;cin>>q;
    while(q--)
    {
        char c;
        int l,r;
        cin>>c>>l>>r;

        if(c=='Q')
        {
            tree ans=query(1,1,n,l,r);
            cout<<(ans.max1+ans.max2)<<"\n";
        }
        else
        {
            update(1,1,n,l,r);
        }
    }
}
