#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define ms(a,b)        memset(a,b,sizeof(a))
#define PI             acos(-1.0)
#define ll             long long int
#define pii            pair< int, int >
#define READ           freopen("in.txt","r",stdin)
#define WRITE          freopen("out.txt","w",stdout)
#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       ((a)*(b))/gcd(a,b)
#define MAX             (int)(1e6+5)
#define MOD            (ll)(1e9+7)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x)          x.begin(),x.end()
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

int sf[MAX];
ll ND[MAX],dp[MAX];

void sieve()
{
    for(int i=1;i<MAX;i++)sf[i]=i;
    for(int i=4;i<MAX;i+=2)
        sf[i]=2;
    for(int i=3;i*i<MAX;i+=2)
    {
        if(sf[i]==i)
        {
            for(int j=i*i;j<MAX;j+=2*i)
            {
                sf[j]=i;
            }
        }
    }

}

ll nod(ll n)
{
    map<ll,ll> mp;
    ll cnt=1;
    while(n>1)
    {
        int x=sf[n];
        cnt/=(mp[x]+1);
        mp[x]++;
        cnt*=(mp[x]+1);
        n/=x;
    }
    return cnt;
}

int main()
{
    // READ;
    // WRITE;
    IOS;
    sieve();
    int mx=1,last=1;
    ND[mx]=1;
    for(int i=1;i<MAX;i++)
    {
        int X=nod(i);
        if(mx<=X)
        {
            mx=X;
            ND[mx]=i;
        }
        dp[i]=ND[mx];
    }
    int ts;
    cin>>ts;
    while(ts--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
