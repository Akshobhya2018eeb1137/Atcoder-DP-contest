#include<iostream>
#include <utility>
#include<bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define ld long double
// #define loop(i,a,b) for(ll i=a;i<b;i++)
// #define inll(n) ll n;cin>>n;
// #define instr(s)  string s;cin>>s;
// #define inarr(a,n)  ll*a = new ll[n];loop(i,0,n)cin>>a[i]; 
// #define invec(v,n)  vector<ll> v(n);loop(i,0,n)inll(v[i])
// #define arr(a,n) ll*a = new ll[n];
// #define outarr(a,n) loop(i,0,n)cout<<a[i]<<" ";cout<<endl;
#define pb push_back
#define mp make_pair
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector <int>
#define vb vector <bool>
#define vll vector <ll>
#define vc vector <char>
#define clr(a) memset(a,0,sizeof(a))
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define infd 1e+18
#define inf 101901199101
#define mod 1000000007
using namespace std;
inline ll min(ll a,ll b)
{
    return (a<b?a:b);
}
inline ll max(ll a,ll b)
{
    return (a<b?b:a);
}


void swap(ll*a,ll*b)
{
    ll t  = *a;
    *a =*b;
    *b = t;
}
void revere(string &s)
{
    for(ll i = s.length()-1;i>=ceil(s.length()/2);i--)
     swap(s[i],s[s.length()-1-i]);
}
bool isValidParenthesis(string s)
{
    int c = 0;
    for(char i:s)c = (i=='('?c+1:c-1);
    if(c!=0)return 0;
    return 1;
}


string substr(string s,int i,int j)
{
    if(i>j)return "";
    string n;
    for(int k = i;k<j;k++)
    {
        n+=s[k];
    }
    return n;
}

int ans(string s, int i,int j)
{
    if(i==j||j>s.length()||i>j||s.length()==0||s.length()==1)return 0;
    if(substr(s,i,j)=="()")return 1;
    if(isValidParenthesis(substr(s,i+1,j-1))) return 2*ans(s,i+1,j-1);
    int ind = i;
    for(int k = i+1;k<j;k++)
    {
        if(isValidParenthesis(substr(s,i,k+1)))
        {
            ind = k+1;
            break;
        }
    }
    return ans(s,i,ind) + ans(s,ind,s.length());
}

ll h,w;
ll call (string str[],ll p,ll q,ll r,ll s)
{
    ll maxo= -894793649;
    if(p>=h||q>=w||r>=h||s>=w||p<0||q<0||r<0||s<0)return -18789769434429;
    else if(str[p][q]=='#')return -10979879433443;
    else if(p==r&&q==s)return 0;
    else
    {
        ll x;
        x = 1 + call(str,p+1,q,r,s);printf("calling for %lld %lld\n",p+1,q);
        if(maxo<x)maxo = x;
        x = 1 + call(str,p-1,q,r,s);printf("calling for %lld %lld\n",p-1,q);
        if(maxo<x)maxo = x;
        x = 1 + call(str,p,q+1,r,s);printf("calling for %lld %lld\n",p,q+1);
        if(maxo<x)maxo = x;
        x = 1 + call(str,p,q-1,r,s);printf("calling for %lld %lld\n",p,q-1);
        if(maxo<x)maxo = x;
    }
    return maxo;
}

int main()
{
    ll n;scanf("%lld",&n);
    vector<ll>dp(3,0);
    for(ll day = 1;day<=n;++day)
    {
        vector<ll>inp(3,0);
        for(ll &x: inp)scanf("%lld",&x);
        vector<ll> newdp(3, 0);

        if(day==1)
        dp = inp;
        else
        {
            for(ll cur =  0;cur<3;++cur)
            {
                for(ll pr = 0;pr<3;++pr){
                    if(cur!=pr)
                    {
                        newdp[cur] = max(newdp[cur], inp[cur] + dp[pr]);
                    }
                }
            }
            dp.swap(newdp);
        }
    }
    sort(dp.begin(), dp.end());
    cout<<dp.back()<<endl;
}
