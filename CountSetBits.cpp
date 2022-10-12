//Problem Link-https://practice.geeksforgeeks.org/problems/set-bits0143/1

/*
    Description:
        Given a positive integer N, print count of set bits in it.
    
    Approach;
        CPP STL __builtin_popcount
*/

#include<bits/stdc++.h>
using namespace std;
int setBits1(int N) {//TC: O(logN) SC:O(1)
    if(N==0)
        return 0;
    else
        return (N&1) + setBits1(N>>1);
}


int setBits2(int N) {//TC: O(logN) SC:O(1)
    int count=0;
    while(N)
    {
        count+=(N&1);
        N>>=1;
    }
    return count;
}

//Brian Kernighan's Algorithm:
int setBits3(int N) {//TC: O(logN) SC:O(1)
    int count=0;
    while(N)
    {
        N=N&(N-1);
        count++;
    }
    return count;
}


int countbits(int n)
{
    return __builtin_popcount(n);
}


int main(){
    int n;cin>>n;
    int ans=countbits(n);
    cout<<ans<<"\n";
    return 0;
}