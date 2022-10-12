//Problem Link-https://practice.geeksforgeeks.org/problems/power-set4302/1

/*
    Description:
        Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

    Approach:
        Using recursion
    Approach 2:
        Using Bit
*/

#include<bits/stdc++.h>
using namespace std;
void solve(int index, string output, vector<string>&ans, string s)
{
    //base case
    if(index>=s.length())
    {
        if(output.length()>0)
        {
            ans.push_back(output);
        }
        return;
    }
    
    //not pick
    solve(index+1, output, ans, s);
    
    //pick character from str
    output.push_back(s[index]);
    solve(index+1, output, ans, s);
}
vector<string> subsequences(string s)
{
    vector<string>ans;
    string output="";
    solve(0, output, ans, s);
    sort(ans.begin(), ans.end());
    return ans;
}
vector<string> AllPossibleStrings(string s)
{
    vector<string>ans;
    int size=s.size();
    int n=1<<size;
    for(int i=0;i<n;i++)//if length is 3 then it runds for 0-7
    {
        string sub="";
        for(int j=0;j<size;j++)
        {
            if((i&(1<<j))>0)//checks if the position has set bit, if setbit then include substring
                sub+=s[j];
        }
        if(sub.size()>0)
            ans.push_back(sub);//insert substring in answer vector
    }
    sort(ans.begin(),ans.end());//print answer in ascending order (subsequences)
    return ans;//return ans
}
int main()
{
    string s;cin>>s;
    vector<string>ans=AllPossibleStrings(s);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}