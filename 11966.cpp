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
#define pdd             pair< double , double>
using namespace std;
using namespace __gnu_pbds;

double dist(pdd a,pdd b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second- b.second)*(a.second-b.second));
}

int vis[2001];
vector<int> adj[2001];

void dfs(int u)
{
    vis[u]=1;
    for(auto v: adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ms(vis,0);
        int n;
        double d;
        cin>>n>>d;
        for(int i=0; i<n; i++)
            adj[i].clear();
        vector<pdd> v(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i].first>>v[i].second;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double dd = dist(v[i],v[j]);
                if(dd<=d)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }
        cout<<"Case "<<++cs<<": "<<cnt<<"\n";
    }
    return 0;
}
