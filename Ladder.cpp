#include<iostream>
using namespace std;

//Recursion
int ways(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }

    int ans = ways(n-1)+ways(n-2)+ways(n-3);
    return ans;
}

//Top down DP
int waysDP()
{
    // Like Fibonacci
}

//Bottom Up Approach
int waysBP(int n,int k)
{
    int *dp = new int[n];
    dp[0]=1;

    for(int step=1 ; step<=n; step++)
    {
        dp[step] = 0;
        for(int jump=1; jump<=k ; jump++)
        {
            if((step -jump) >= 0)
                dp[step] += dp[step-jump];
        }
    }

}

// Optimal
int way(int n, int k)
{
    int *dp = new int[n];
    dp[0]=1;

    for(int step=1 ; step<=n; step++)
    {
        dp[step] = 0;

    }
}
int main()
{
    cout << ways(4);
}
