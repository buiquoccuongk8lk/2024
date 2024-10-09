#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define fi first
#define se second
#define el '\n'
#define TASK "jog"
#define openfile if(fopen(TASK".inp","r")) {freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);}
using namespace std;

/* Author: Mai Ngoc Phu */
/*Khai Bao*/
const long long inf=1e18;
const int LO=17;
const int CH=27;
const int N=1e4+5;
int n,r,m;
int a[100005];
//void add(int &x,const int &y){x+=y;if(x>=sm)x-=sm;}
//void sub(int &x,const int &y){x-=y;if(x<0)x+=sm;}
/*END*/
void doc()
{
    cin>>n>>r>>m;
    fr(i,1,m)
    {
        cin>>a[i];
    }
}   
namespace sub1
{
    ll res[N];
    vector <int> cycle;
    bool check[N];
    int start[N];
    int cnt[N];
    void xuly()
    {
        int pos=0;
        fr(i,1,m)
        {
            pos=(pos+a[i])%n;
            if(pos<0) pos+=n;
            cnt[pos]++;
        }
        int cur=0;
        while(!check[cur])
        {
            check[cur]=1;
            cycle.pb(cur);
            cur=(cur+pos)%n;
        }
        for(auto p:cycle)
        {
            start[p]+=r/cycle.size();
        }
        if(r%cycle.size()!=0)
        {
            int tmp=(r%cycle.size());
            fr(i,0,tmp-1)
            {
                start[cycle[i]]++;
            }
        }
        fr(i,0,n-1)
        {
            fr(j,0,n-1)
            {
                int t=i+j;
                if(t>=n)
                {
                    t-=n;
                }
                res[t]+=1ll*start[i]*cnt[j]; 
            }
        }
        res[0]++;
        fr(i,0,n-1) cout<<res[i]<<" ";
    }
}
namespace sub2
{
    void xuly()
    {

    }
}
void time()
{
    cerr<< endl<<"Luattapcode: "<<clock()<<"ms"<<endl;
}
main()
{
    ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
    // openfile
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    doc();
    sub1::xuly();
    time();
}