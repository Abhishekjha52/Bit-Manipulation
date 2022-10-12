//Problem Link-https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
/*
    Description:
        Given a number N having only one ‘1’ and all other ’0’s in its binary representation, 
        find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. 
        Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

    Approach:
        if number is nt a power of 2 then return -1 else log2(n)+1;
*/
#include<bits/stdc++.h>
using namespace std;
int findPosition(int N) {
    // If only set bit then n should pe a power of 2.
    if(N == 0 || (N & (N-1)) != 0)
        return -1;
    return log2(N)+1;
}
int main()
{
    int n;cin>>n;
    int ans=findPosition(n);
    cout<<ans<<"\n";
    return 0;
}