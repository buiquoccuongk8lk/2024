#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#define             pb  push_back  
#define             ll  long long
#define             se  second 
#define             fi  first
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const long long inf = 1e18;
const ll N = 2e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9+7 /*1234567891*/ , base =311 ;
 
ll n,d;
 
struct bg
{
    ll id,i;
};
 
bg x[N],y[N];
 
void doc()
{
    cin>>d>>n;
    fu(i,1,n)
    {
        cin>>x[i].id>>y[i].id;
        x[i].id+=1e9;
        y[i].id+=1e9;
        x[i].i=y[i].i=i;
    }
}
    
void pre()
{
    
}
 
unordered_map<ll,unordered_map<ll,ll>> mpx,mpy;
ll cnt[1007][1007];
 
void sol()
{
 
    // cout<<-5%3<<el;
    fu(i,1,n)
    {
        mpx[x[i].id%d][i]++;
        mpy[y[i].id%d][i]++;
        cnt[x[i].id%d][y[i].id%d]++;
    }
    ll ans=inf;
    fu(i,0,d-1)
    {
        fu(j,0,d-1)
        {
            // unordered_set<ll> s;
            ans=min(ans,(ll)(mpx[i].size()+mpy[j].size())-cnt[i][j]);
        }
    }
    cout<<ans;
 
}
 
int mlt=0;
int test=1;
signed main(void)
{
    #define TASK  "social-distancing"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    if(mlt) cin>>test;
    doc();
    fu(i,1,test)
    {
        pre();
        sol();
    }
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}