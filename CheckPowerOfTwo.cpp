//Problem Link-https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

/*
    Description:
        Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

*/  

#include<bits/stdc++.h>
using namespace std;
bool isPower(int n)
{
    if(n==0)
        return false;
  
    if(ceil(log2(n)) == floor(log2(n)))
        return true;
    return false;
}
bool isPower(int n)
{
    if(n==0)
        return false;
    return (n&(n-1))==0;
}
int main()
{
    int n;cin>>n;
    bool ans=isPower(n);
    if(ans) 
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
    return 0;
}