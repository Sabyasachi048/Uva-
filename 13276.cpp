#include <bits/stdc++.h>
#define prt_cs                  printf("Case %d: ",cs)
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

int main()
{
//    READ;
//    WRITE;
    int ts;
    scanf("%d",&ts);
    for(int cs=1;cs<=ts;cs++)
    {
        ll E,P,K,R;
        scanf("%lld %lld %lld %lld",&E,&P,&K,&R);
        prt_cs;
        if(P*K>=E)
        {
            ll  kk = E/P;
            if(E%P!=0)kk++;
            printf("%lld",kk);
        }
        else if(P*K-R<=0)
        {
            printf("-1");
        }
        else
        {
            double xx = ((E-R)*1.0)/(1.0*(P*K-R));
            double kk= xx*K;
            kk=ceil(kk);
            ll ans = kk;
            while(E-ans*P+((ans%K==0)?((ans/K)-1):(ans/K))*R>0)
            {
                ans++;
            }
            printf("%lld",ans);
        }
        printf("\n");
    }
    return 0;
}
