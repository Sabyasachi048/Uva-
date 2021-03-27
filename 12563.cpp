#include<bits/stdc++.h>
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

using namespace std;


const int lim=9005;
int dp[lim+687],a[100],cdp[lim+687];

int main()
{
//    READ;
//    WRITE;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ts,cs=0;
    cin>>ts;
    while(ts--)
    {
        ms(dp,-1);
        ms(cdp,-1);
        ms(a,0);
        int n,t;
        cin>>n>>t;
        t=min(lim,t);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int mx=0;

        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=t-1;j>=a[i-1];j--)
            {
                    if(a[i-1]<=j)
                    {
                    dp[j]=max(dp[j-a[i-1]]+1,dp[j]);
                    }
                    mx=max(mx,dp[j]);
            }
        }
        int ans=0,c=0,trn=mx;
        for(int i=0;i<t;i++)
        {
                if(dp[i]>=mx)
                {

                    c=i;
                    if(c>ans)
                    {
                        ans=c;
                        trn=dp[i];
                    }
                }
        }
        if(ans<t)
        {
            ans+=678;
        }
        if(ans>0 && trn==0)trn++;
        cout<<"Case "<<++cs<<": "<<trn<<" "<<ans<<"\n";
    }
    return 0;
}
