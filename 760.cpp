#include <bits/stdc++.h>
#define prt_cs                  printf("Case %lld: ",cs)
#define pb                      push_back
#define sqr(x)                  (x)*(x)
#define sf                      scanf
#define pf                      printf
#define ms(a,b)                 memset(a, b, sizeof(a))
#define db                      double
#define ll                      long long int
#define MOD                     100000007
#define PI                      2*acos(0.0)
#define pii                     pair< int, int >
#define READ                    freopen("in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               (((a)*(b))/gcd(a,b))
#define loop(i,n)               for(ll i=0;i<n;i++)
#define MAX                     100005

using namespace std;

int p[700],c[700],lcp[700];
unordered_map<string,bool> mp;


 void rsort(int p[],int c[],int n)
 {
     {
         int p_new[n+1]={},cnt[n+1]={},pos[n+1]={};
         for(int i=0;i<n;i++)
            cnt[c[i]]++;
         pos[0]=0;
         for(int i=1;i<n;i++)
             pos[i]=pos[i-1]+cnt[i-1];
        for(int i=0;i<n;i++)
        {
            int k = c[p[i]];
            p_new[pos[k]]=p[i];
            pos[k]++;
        }
        for(int i=0;i<n;i++)
            p[i]=p_new[i];
     }
 }

void computeSA(string s)
{
    ms(p,0);
    ms(c,0);
    int n=s.size();
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
                c[p[i]]++;
        }
    }
    int k=0;
    while((1<<k)<n)
    {
        int c_new[n+1]={};
        for(int i=0;i<n;i++)
        {
            p[i]=(p[i]-(1<<k)+n)%n;
        }
        rsort(p,c,n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            pii now = {c[p[i]],c[(p[i]+(1<<k))%n]};
            pii prev = {c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            c_new[p[i]]=c_new[p[i-1]];
            if(now!=prev)
                c_new[p[i]]++;
        }
        for(int i=0;i<n;i++)c[i]=c_new[i];
        k++;
    }

}

void computeLCP(string s)
{
    int n=s.size();
    int k=0;
    for(int i=0;i<n;i++)
    {
        int pi=c[i];
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
    string a,b;
    int cs=0;
    while(getline(cin,a))
    {
        mp.clear();
        getline(cin,b);
        if(cs)
        printf("\n");
        ms(lcp,0);
        string s;
        if(a.size()<b.size())swap(a,b);
        int sza=a.size()+1;
        s+=a;
        s+="#";
        s+=b;
        s+="$";
        int n=s.size();
        computeSA(s);
        computeLCP(s);
        vector<int> sec(n,0);
        for(int i=0;i<n;i++)
        {
            if(p[i]<sza)
            sec[i]=1;
            else sec[i]=2;
        }
        int mx=-1;
        for(int i=0;i<n-1;i++)
        {
            if(sec[i]!=sec[i+1])
            {
                mx=max(lcp[i+1],mx);
            }
        }
        vector<string> v;
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(sec[i]!=sec[i+1] && lcp[i+1]==mx && mx>0)
            {
                cnt++;
                string str = s.substr(p[i],mx);
                if(!mp[str])
                {
                    v.push_back(str);
                    mp[str]=1;
                }
            }
        }
        if(!cnt)
        {
            cout<<"No common sequence.\n";
        }
        else{
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<"\n";
            }
        }
        cs++;
        getline(cin,a);
    }
    return 0;
}
