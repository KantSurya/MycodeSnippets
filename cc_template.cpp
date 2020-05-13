/*
    Author : Surya Kant
    Created : 14-05-2020
    
    01. num_to_string // Binary representation of a number upto length bits
*/

#include<bits/stdc++.h>
using namespace std;

string num_to_string(int x,int length)  // Binary representation of a number
{
    string s="";
    while(x)
    {
        string temp=s;
        s=x%2+'0';
        s=s+temp;
        x/=2;
    }

    while(s.size()<length)
    {
        string temp=s;
        s=0+'0';
        s+=temp;
    }
    return s;
}
int main()
{
    cout<<"Enter -9 to end the program\n";
    while(1)
    {
        int x;
        cin>>x;
         if(x==-9)
         return 0;
        string s=num_to_string(x,10);
        cout<<s<<"\n";
    }
}
