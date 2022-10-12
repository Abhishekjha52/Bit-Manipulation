//Problem Link-https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/#:~:text=Given%20an%20integer%20n%2C%20calculate,*%2C%20%2F%20and%20pow().&text=A%20Simple%20Solution%20is%20to%20repeatedly%20add%20n%20to%20result.

/*
    Description:
        Given an integer n, calculate the square of a number without using *, / and pow(). 

    Approach:
        use for loop and add n value to ans n times

    Approach 2:

        square(n) = 0 if n == 0
        if n is even 
            square(n) = 4*square(n/2) 
        if n is odd
            square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

        Examples
        square(6) = 4*square(3)
        square(3) = 4*(square(1)) + 4*1 + 1 = 9
        square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49
        How does this work? 

        If n is even, it can be written as
        n = 2*x can be written as x=n>>1 => x=n/2
        n2 = (2*x)2 = 4*x2 //can be written as squareof(x)<<2 ==> squareof(x)*pow(2, 2)
        If n is odd, it can be written as 
        n = 2*x + 1
        n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
        floor(n/2) can be calculated using a bitwise right shift operator. 2*x and 4*x can be calculated 
*/

#include<bits/stdc++.h>
using namespace std;
int squareOfNumber(int n)//TC:O(N)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=n;
    }
    return ans;
}
int square(int n){
    if(n==0)return 0;
    if(n<0)n=-n;
    int x=n>>1;//n/2
    if(n&1)//if odd =>n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
        return ((square(x)<<2)+(x<<2)+1);
    else
        return (square(x)<<2);

}
int main()
{
    int n;cin>>n;
    int ans=square(n);
    cout<<ans<<"\n";
    return 0;
}