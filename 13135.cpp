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
#define MAX             (int)(1e5+5)
#define MOD            (ll)(1e9+7)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x)          x.begin(),x.end()
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const ll LIM=50000005;
ll dp[LIM];


ll fn(ll n)
{
    return ((n+1)*(n+2))/2;
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    ms(dp,-1);
    for(int i=0;i<10000;i++)
    {
        ll x=fn(i);
        if(x>LIM-5)break;
        dp[x]=i;
    }
    int ts;
    cin>>ts;
    while(ts--)
    {
        ll S;
        cin>>S;
        if(dp[S]!=-1)
        {
            cout<<dp[S]<<"\n";
        }
        else
        {
            cout<<"No solution\n";
        }
    }
    return 0;
}
