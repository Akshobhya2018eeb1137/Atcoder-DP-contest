#include<iostream>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
typedef long long int ll;
typedef long long int ull;
using namespace std;

inline ll min(ll a,ll b)
{
    return (a>b?b:a);
}

inline ll digsum(ll n)
{
    if(n<0)return -1;
    ll sum = 0;
    while (n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void findBlacks(vector< vector < bool >  > &present, vector<string>&s,ll w,ll d,ll x,ll y)
{
    present[x][y] = 1;
            if(x+1<d&&s[x+1][y]=='.'&&present[x+1][y]!=1)
                findBlacks(present,s,w,d,x+1,y);
            if(x-1>=0&&s[x-1][y]=='.'&&present[x-1][y]!=1)
                findBlacks(present,s,w,d,x-1,y);
            if(y-1>=0&&s[x][y-1]=='.'&&present[x][y-1]!=1)
                findBlacks(present,s,w,d,x,y-1);
            if(y+1<w&&s[x][y+1]=='.'&&present[x][y+1]!=1)
                findBlacks(present,s,w,d,x,y+1);
        return;
}

void print(ll s[], ll i,ll n)
{
    if(i>=n||i<0)return;
    cout<<s[i]<<" ";
    print(s,i+2,n);
    if(i+2==n)
        cout<<s[i+1]<<" ";
    if(i-1>0)
    cout<<s[i-1]<<" ";
    return;
}

bool isprime(ll n)
{
    if(n==2||n==3)return 1;
    for(ll i =2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}

ll path(string s1,string s2,ll curr)
{
    if(s1==s2||curr>=4)return 0;
    ll mini = 879686699;
    for(ll i =0;i<4&&i!=curr;i++)
    {
        cout<<"came]\n";
        for(ll k= 0;k<=9&&k!=s1[curr]-'0';k++)
        {
            char c = s1[curr];
            s1[curr] = k+'0';
            if(isprime(atoll(s1.c_str()))&&k+'0'!=c)
                {
                    mini = min(mini,1 + path(s1,s2,curr+1));
                    cout<<"no chosen "<<s1<<endl;
                }
            s1[curr] =  c;
        }
    }
    return mini;
}

int main()
{
    string s,t;cin>>s>>t;
    ll dp[s.length()+1][t.length()+1];
    memset(dp,0,sizeof(dp));
    for(ll i =0;i<s.length()+1;i++)dp[i][0];
    for(ll i = 0;i<t.length()+1;i++)dp[0][i];

    for(ll i = 1;i<s.length()+1;i++)
    {
        for(ll j =1;j<t.length()+1;j++)
        {
            if(s[i-1] == t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // for(ll i = 0;i<s.length()+1;i++)
    // {
    //     for(ll j = 0;j<t.length()+1;j++)cout<<dp[i][j];
    //     cout<<endl;
    // }
    // Following code is used to print LCS
    ll m = s.length();
    ll n = t.length();
   int index = dp[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   string X = s;
   string Y = t;
   X.c_str();
   Y.c_str();
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   cout<< lcs; 
}
