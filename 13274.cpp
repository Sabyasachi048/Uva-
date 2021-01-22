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
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

set_pbds(int) adj[1001];

int dp[1001];

int dfs(int u,int p,int k)
{
    if(adj[u].size()<k)return 1;
    int ans=0;
    priority_queue<pii>  pq;
    for(auto v: adj[u])
    {
        if(v!=p)
        {
            ans=dfs(v,u,k);
            pq.push({ans,v});
        }
    }
    if(pq.size()<k)return 1;
    ans=1;
    int j=0;
    while(j<k)
    {
        ans+=pq.top().first;
        pq.pop();
        j++;
    }
    dp[u]=ans;
    return ans;
}

int main()
{
//    READ;
//    WRITE;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ms(dp,-1);
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n;i++)
            adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        ll ans=dfs(1,0,k);
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
