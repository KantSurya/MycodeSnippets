// Store ncr by recursion and dynamic programming
// ncr+nc(r-1)=(n+1)cr
#include<iostream>
using namespace std;
int a[1000][1000]={0};
int ncr(int n, int r)
{
	if(n<r) return 0;
	if(r==0 || r==n) return 1;
	if(a[n][r]!=0) return a[n][r];
	a[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
	return a[n][r];
}
int main()
{
	cout<<"heha";
	while(1)
	{
		int n,r;
		cin>>n>>r;
		int x=ncr(n,r);
        cout<<x<<"\n";
	}
}
