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
#define MAX             (int)(1e4+5)
#define MOD            (ll)(1e9+7)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x)          x.begin(),x.end()
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

ll Tree[4*MAX],lazy[4*MAX];

void push(int node,int b,int e)
{
    if(lazy[node])
    {
        int left=node<<1,right=left+1;
        if(b!=e)
        {
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
            Tree[left]+=lazy[node];
            Tree[right]+=lazy[node];
        }
    }
    lazy[node]=0;
}

void update(int node,int b,int e,int i,int j)
{
    if(b>j || e<i || b>e)return;
    push(node,b,e);
    if(b>=i && e<=j)
    {
        lazy[node]+=1;
        Tree[node]+=1;
        push(node,b,e);
        return;
    }
    ll left=node<<1,right=left+1,mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    Tree[node]=Tree[left]+Tree[right];
}

ll query(int node,int b,int e,int i,int j)
{
    if(b>e || b>j || e<i)
        return 0;
    push(node,b,e);
    if(b>=i && e<=j)
    {
        return Tree[node];
    }

    int left=node<<1,right=left+1,mid=(b+e)/2;
    ll r1,r2;
    r1=query(left,b,mid,i,j);
    r2=query(right,mid+1,e,i,j);
    return r1+r2;
}

int main()
{
//    READ;
//    WRITE;
    IOS;
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        ms(Tree,0);
        ms(lazy,0);
        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            update(1,0,10000,max(0,x-y),min(10000,x+y));
        }
        ll mx=0;
        for(int i=0; i<=10000; i++)
        {
            mx=max(mx,query(1,0,10000,i,i));
        }
        cout<<mx<<"\n";
    }
    return 0;
}
