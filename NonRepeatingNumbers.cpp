//Problem Link-https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

/*
    Description:
        Given an array A containing 2*N+2 positive numbers, 
        out of which 2*N numbers exist in pairs whereas the other two 
        number occur exactly once and are distinct. 
        Find the other two numbers. Return in increasing order.

    Approach:
        



*/

#include<bits/stdc++.h>
using namespace std;
//First Approach using map
vector<int> singleNumber(vector<int> nums) 
{
    vector<int>ans;
    map<int, int>mp;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }
    
    for(auto c:mp)
    {
        if(c.second==1)
            ans.push_back(c.first);
    }
    return ans;
}

//Second approach using Bits
vector<int> singleNumber(vector<int> nums) 
{
    int res=0;
    for(auto x:nums)
        res = res^x;

    int n = res & ~(res-1);

    int grp1=0,grp2=0;

    for(auto x:nums)
    {
        if((n&x)!=0)
            grp1 = grp1^x;
        else
            grp2 = grp2^x;
    }

    vector<int>v;
    v.push_back(grp1);
    v.push_back(grp2);
    sort(v.begin(),v.end());
    return v;
}

int main()
{
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>ans=findNumbers(arr, n);
    for(auto c:ans)
        cout<<c<<" ";
    cout<<"\n";
    return 0;
}