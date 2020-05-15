#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
long double eps = 1e-9;
inline ll max(ll a, ll b)
{
	return (a>b?a:b);
}
inline ll min(ll a, ll b)
{
	return a<b?a:b;
}
ll mul(ll x, ll y)
{
	return ((x % mod)* (y%mod))%mod;
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

inline ll inv(ll x)
{
    return binpow(x, mod - 2);
}
inline ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}

inline ll add(ll x, ll y)
{
    return ((x%mod)+(y%mod))%mod;
}
ll dp[101][100010]
;int main()
{
    ll n, W;cin>>n>>W;
    ll w[n], v[n];
    ll mw = 0;
    for(ll i = 0;i<n;i++)cin>>w[i]>>v[i];
    for(ll i = w[0];i<= W;i++)
    {
       dp[0][i] = v[0];
    }
    for(ll i = 1;i<n;i++)
    {
        for(ll j = 1;j<=W;j++)
        {
            if(j - w[i] < 0)
            {
                dp[i][j] = dp[i - 1][j];continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    
    cout<<dp[n - 1][W];
}
