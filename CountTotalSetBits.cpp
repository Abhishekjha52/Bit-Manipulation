//Problem Link-https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

/*
    Description:
        You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

    Approach:



*/

#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n)//Brute Force TLE
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int ans=__builtin_popcount(i);
        sum+=ans;
    }
    return sum;
}
int count_bits(int n)//O(LOGN)
{
    if(n<=1)
        return n;
    int k = floor(log2(n));
       
    return (k)*pow(2,k-1) + (n- pow(2,k) +1) + count_bits(n- pow(2,k));
}
int main()
{
    int n;cin>>n;
    int ans=countSetBits(n);
    cout<<ans<<"\n";
    return 0;
}