/*
    Problem Statement : https://www.codechef.com/COOK39/problems/PPXOR
    Tutorial : https://www.geeksforgeeks.org/sum-of-xor-of-all-subarrays/
    
    Stackoverlow : https://stackoverflow.com/questions/20113622/algorithm-to-add-sum-of-every-possible-xor-sum-sub-array
    Best SOlution : https://www.codechef.com/viewplaintext/2928504
    
    sum of xor of all subarrays
    Xor, Subarray, Bit manipulation,    
*/

#include<iostream>
using namespace std;
void XorSumSubarrays(int arr[],int n)
{
    long long sum=0;
    for(int i=0;i<32;++i)
    {
        int x=(1<<i);
        
        int c_odd=0;
        bool odd=false;
        
        for(int j=0;j<n;++j)
        {
            if(arr[j]&x)
            odd=(!odd);
            if(odd)
            c_odd++;
        }
        
        for(int j=0;j<n;++j)
        {
            sum+=(x*c_odd);
            if(arr[j]&x)
            c_odd=n-j-c_odd;
        }
    }
    cout<<sum<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int arr[n];
        for(int i=0;i<n;++i)
        cin>>arr[i];
        XorSumSubarrays(arr,n);
        
    }
}
