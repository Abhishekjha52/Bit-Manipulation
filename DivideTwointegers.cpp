//Problem Link-https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1

/*
    Description:
        Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.
    
    
*/

#include<bits/stdc++.h>
using namespace std;
/*
    Approach: 
        Keep subtracting the divisor from the dividend until the dividend becomes less than the divisor. 
        The dividend becomes the remainder, and the number of times subtraction is done becomes the quotient. 
        Below is the implementation of the above approach : 
*/
long long divide(long long dividend, long long int divisor)
{
 
    // Calculate sign of divisor i.e.,
    // sign will be negative only if
    // either one of them is negative
    // otherwise it will be positive
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
    // Update both divisor and
    // dividend positive
    dividend = abs(dividend);
    divisor = abs(divisor);
 
    // Initialize the quotient
    long long quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
 
    // Return the value of quotient with the appropriate
    // sign.
    return quotient * sign;
}


long long divide(long long dividend, long long divisor) 
{
    long long n=dividend, m=divisor;
    
    int sign=(n<0)^(m<0)?-1:1;
    
    n=abs(n), m=abs(m);
    
    long long quotient=0, temp=0;
    
    for(long long i=31;i>=0;i--){
        if(temp+(m<<i)<=n)
        {
            temp+=(m<<i);
            quotient=quotient|(1LL<<i);
        }
    }
    
    return quotient*sign;
    
}
int main()
{
    long long int dividend, divisor;
    cin>>dividend>>divisor;
    long long int ans=divide(dividend, divisor);
    cout<<ans<<"\n";
    return 0;
}
