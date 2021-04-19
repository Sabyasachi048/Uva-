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
#define MAX             (int)(2005)
#define MOD            (ll)(1e9+7)
#define IOS             ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x)          x.begin(),x.end()
#define set_pbds(T)         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

int sf[MAX];
int mark[512];

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


int main()
{
    // READ;
    // WRITE;
    IOS;
    sieve();
    sf[0]=-1;
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ms(mark,0);
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            mark[(int)s[i]]++;
        }
        string ans;
        for(int i=0;i<256;i++)
        {
            if(mark[i]>1 && sf[mark[i]]==mark[i])
            {
                ans+=(char)(i);
            }
        }
        if(ans.length()==0)
        ans="empty";
        cout<<"Case "<<++cs<<": "<<ans<<"\n";
    }
    return 0;
}
