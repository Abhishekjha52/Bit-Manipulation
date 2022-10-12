//Problem Link-https://practice.geeksforgeeks.org/problems/bit-difference/0

/*
    Description:
        You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

    Approach:
        Find xor of two values and count no of set bits in res xor value

*/

#include<bits/stdc++.h>
using namespace std;
int countBitsFlip(int a, int b){
    int ans=a^b;
    return __builtin_popcount(ans);
}
int main()
{
    int a, b;cin>>a>>b;
    int ans=countBitsFlip(a, b);
    cout<<ans<<"\n";
    return 0;
}