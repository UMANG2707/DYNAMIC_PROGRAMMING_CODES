#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Min Coin Recursion
int MinCoin(int cn[] , int n , int amount)
{
    if(amount==0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amount >= cn[i])
        {
            int sm = MinCoin(cn,n,amount-cn[i]);
            if(sm != INT_MAX)
            {
                ans = min(ans,sm+1);
            }
        }
    }
    return ans;
}

//Bottom Up
int CoinsNeed(int cn[],int n,int amount)
{
    int *dp = new int[amount];
    for(int i=0;i<=amount; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int rupee = 0; rupee <=amount; rupee++)
    {
        for(int coins = 0 ;coins<n ; coins++)
        {
            if(cn[coins] <= rupee)
            {
                int sm = dp[rupee - cn[coins]];
                if(sm != INT_MAX)
                {
                    dp[rupee] = min(sm+1,dp[rupee]);
                }
            }
        }
    }
    return dp[amount];
}
int main()
{
    int cn[] = {1,4,6};
    int n =3;
    int amount = 8;
    cout << MinCoin(cn,n,amount) << endl;
    cout << CoinsNeed(cn,n,amount);

}
