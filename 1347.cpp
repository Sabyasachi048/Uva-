#include <bits/stdc++.h>
#define prt_cs                  printf("Case %lld: ",cs)
#define sqr(x)                  (x)*(x)
#define ms(a,b)                 memset(a, b, sizeof(a))
#define db                      double
#define ll                      long long int
#define MOD                     100000007
#define PI                      acos(-1.0)
#define pii                     pair< int, int >
#define READ                    freopen("in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               (((a)*(b))/gcd(a,b))
#define MAX                     100005

using namespace std;

struct Pt{
    double x,y;
    bool operator<(const Pt& p)
    {
        if(x==p.x)
            return y<p.y;
        return x<p.x;
    }
};

double dist(Pt a,Pt b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

vector<Pt> v;

double dp[1001][1001];

double solve(int i,int j)
{
    int n=v.size();
    if(i==n-1)return dist(v[j],v[n-1]);
    if(j==n-1)return dist(v[i],v[n-1]);
    int k=max(i,j)+1;
    if(dp[i][j]!=-1)return dp[i][j];
    double r1,r2,ans=0;
    r1=solve(i,k)+dist(v[j],v[k]);
    r2=solve(k,j)+dist(v[i],v[k]);
    ans=min(r1,r2);
    return dp[i][j]=ans;
}

int main()
{
//    READ;
//    WRITE;
    int n;
    while(scanf("%d",&n)==1)
    {
        v.clear();
        for(int i=0;i<n;i++)
        {
            Pt p;
            scanf("%lf %lf",&p.x,&p.y);
            v.push_back(p);
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        double ans=solve(0,0);
        printf("%.2f\n",ans);
    }
    return 0;
}
