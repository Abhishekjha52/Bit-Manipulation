//Problem Link-https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1

/*
    Description:
        Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.
                    L       R
        A = 1 0 1 0 1 0 1 0 1 0 1
        B = 1 0 0 1 0 0 1 1 0 0 1

    res  =  1 0 0 1 1 0 1 1 1 0 1

    create a mask to extract values from L to R
    like    0 0 0 0 1 0 1 0 1 0 0 

    then OR with B to get res

            1 0 0 1 0 0 1 1 0 0 1
    mask    0 0 0 0 1 0 1 0 1 0 0
    OR
    res     1 0 1 1 1 0 1 1 1 0 1


    to create mask we need to AND with A with another mask
         1 0 1 0 1 0 1 0 1 0 1
    AND  0 0 0 0 1 1 1 1 1 0 0
    RES  0 0 0 0 1 0 1 0 1 0 0
*/

#include<bits/stdc++.h>
using namespace std;
int setSetBit(int x, int y, int l, int r){
    if(x==y)return x;
    if(l<1 || r>32)return 0;
        
    long long mask=1LL<<(r-l+1);
    mask--;
    mask= mask<<(l-1);
    
    mask=mask&y;
    x=x|mask;
    
    return x;
    
}
int main(){
    int x, y;cin>>x>>y;
    int l, r;cin>>l>>r;
    int ans=setSetBit(x, y, l, r);
    cout<<ans<<"\n";
    return 0;
}