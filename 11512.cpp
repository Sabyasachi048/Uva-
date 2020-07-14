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



void rsort(vector<int> &p,vector<int> &c)
{
    int n = p.size();
    {
        vector<int> p_new(n,0),cnt(n,0),pos(n,0);
        for(int i=0;i<n;i++)
            cnt[c[i]]++;
        pos[0]=0;
        for(int i=1;i<n;i++)
            pos[i]=pos[i-1]+cnt[i-1];
        for(int i=0;i<n;i++)
        {
            int k= c[p[i]];
            p_new[pos[k]]=p[i];
            pos[k]++;
        }
        p=p_new;
    }
}

void computeSA(string &s,vector<int> &p,vector<int> &c)
{
    int n = s.size();
    {
        vector<pair<char,int>> ss;
        for(int i=0;i<n;i++)
        {
            ss.push_back({s[i],i});
        }
        sort(ss.begin(),ss.end());
        for(int i=0;i<n;i++)
            p[i]=ss[i].second;
        c[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            c[p[i]]=c[p[i-1]];
            if(ss[i].first!=ss[i-1].first)
            {
                c[p[i]]++;
            }
        }
    }
    int k=0;
    while((1<<k)<n)
    {
        vector<int> c_new(n,0);
        for(int i=0;i<n;i++)
            p[i]=(p[i]-(1<<k)+n)%n;
        rsort(p,c);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            c_new[p[i]]=c_new[p[i-1]];
            pii now={c[p[i]],c[(p[i]+(1<<k)%n)]};
            pii prev={c[p[i-1]],c[(p[i-1]+(1<<k)%n)]};
            if(now!=prev)
                c_new[p[i]]++;
        }
        c=c_new;
        k++;
    }
}


void computeLCP(string &s,vector<int> &p,vector<int> &c,vector<int> &lcp)
{
    int n = s.size(),k=0;
    for(int i=0;i<n-1;i++)
    {
        int pi = c[i];
        int j = p[pi-1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k])k++;
        lcp[pi]=k;
        k=max(k-1,0);
    }
}



int main()
{
//    READ;
//    WRITE;
    int ts;
    cin>>ts;
    while(ts--)
    {
        string s;
        cin>>s;
        s+='$';
        int n = s.size();
        vector<int> p(n,0),c(n,0),lcp(n,0);
        computeSA(s,p,c);
        computeLCP(s,p,c,lcp);
        int mx=-1,mxm=-1;
        for(int i=1;i<n;i++)
        {
            if(lcp[i]>mxm)
            {
                mxm=lcp[i];
                mx=p[i-1];
            }
        }
        if(mxm<=0)
        {
            cout<<"No repetitions found!\n";
            continue;
        }
        else {
            string refr = s.substr(mx,mxm);
            int up=-1,low=-1;
            int lo = 0,hi=n-1;
            while(lo<=hi)
            {
                int mid=(lo+hi)/2;
                string str = s.substr(p[mid],min(mxm,n-p[mid]));
                if(str<refr || str==refr)
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }
            up=hi;
            lo = 0,hi=n-1;
            while(lo<=hi)
            {
                int mid=(lo+hi)/2;
                string str = s.substr(p[mid],min(mxm,n-p[mid]));
                if(str==refr || str>refr)
                {
                    hi=mid-1;
                }
                else
                {
                    lo=mid+1;
                }
            }
            low=lo;
            int cnt = (up-low+1);
            cout<<refr<<" "<<cnt<<endl;
        }
    }
    return 0;
}
