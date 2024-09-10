#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e18;
const ll base = 311;
const ll N=2e3+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,r,c;
ll a[N][N],dp[N][N];
vector<pair<ll,ll>> val[N*N];
set<ll> s;

struct bg
{
    ll cur1,id1,cur2,id2,cur3,id3;
}row[N],col[N];

void up(ll i,ll j)
{
    ll val=dp[i][j];
    if(col[j].cur1<val)
    {
        col[j].cur3=col[j].cur2;
        col[j].id3=col[j].id2;
        col[j].cur2=col[j].cur1;
        col[j].id2=col[j].id1;
        col[j].cur1=val;
        col[j].id1=i;//
    }
    else if(col[j].cur2<val)
    {
        col[j].cur3=col[j].cur2;
        col[j].id3=col[j].id2;
        col[j].cur2=val;
        col[j].id2=i;//
    }
    else if(col[j].cur3<val)
    {
        col[j].cur3=val;
        col[j].id3=i;//
    }


    if(row[i].cur1<val)
    {
        row[i].cur3=row[i].cur2;
        row[i].id3=row[i].id2;
        row[i].cur2=row[i].cur1;
        row[i].id2=row[i].id1;
        row[i].cur1=val;
        row[i].id1=j;//
    }
    else if(row[i].cur2<val)
    {
        row[i].cur3=row[i].cur2;
        row[i].id3=row[i].id2;
        row[i].cur2=val;
        row[i].id2=j;//
    }
    else if(row[i].cur3<val)
    {
        row[i].cur3=val;
        row[i].id3=j; //
    }
}


signed main(void)
{
    #define TASK  ""
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }
    cin>>n>>r>>c;
    fu(i,1,n) fu(j,1,n) cin>>a[i][j];
    fu(i,1,n) fu(j,1,n)
    {
        dp[i][j]=-inf;
        val[a[i][j]].pb({i,j});
    }
    vector<ll> ve;
    dp[r][c]=1;
    ll ans=0;
    fu(v,1,1e6)
    {
        for(auto id:val[v])
        {
            ll i=id.fi,j=id.se;
            if(i>1)
            {
                if(row[i-1].id1 && abs(row[i-1].id1-j)>1) dp[i][j]=max(dp[i][j],row[i-1].cur1+1);
                else if(row[i-1].id2 && abs(row[i-1].id2-j)>1) dp[i][j]=max(dp[i][j],row[i-1].cur2+1);
                else if(row[i-1].id3 && abs(row[i-1].id3-j)>1) dp[i][j]=max(dp[i][j],row[i-1].cur3+1);
            }
            if(i<n)
            {
                if(row[i+1].id1 && abs(row[i+1].id1-j)>1) dp[i][j]=max(dp[i][j],row[i+1].cur1+1);
                else if(row[i+1].id2 && abs(row[i+1].id2-j)>1) dp[i][j]=max(dp[i][j],row[i+1].cur2+1);
                else if(row[i+1].id3 && abs(row[i+1].id3-j)>1) dp[i][j]=max(dp[i][j],row[i+1].cur3+1);
            }
            if(j>1)
            {
                if(col[j-1].id1 && abs(col[j-1].id1-i)>1) dp[i][j]=max(dp[i][j],col[j-1].cur1+1);
                else if(col[j-1].id2 && abs(col[j-1].id2-i)>1) dp[i][j]=max(dp[i][j],col[j-1].cur2+1);
                else if(col[j-1].id3 && abs(col[j-1].id3-i)>1) dp[i][j]=max(dp[i][j],col[j-1].cur3+1);
            }
            if(j<n)
            {
                if(col[j+1].id1 && abs(col[j+1].id1-i)>1) dp[i][j]=max(dp[i][j],col[j+1].cur1+1);
                else if(col[j+1].id2 && abs(col[j+1].id2-i)>1) dp[i][j]=max(dp[i][j],col[j+1].cur2+1);
                else if(col[j+1].id3 && abs(col[j+1].id3-i)>1) dp[i][j]=max(dp[i][j],col[j+1].cur3+1);
            }
        }
        for(auto id:val[v])
        {
            ll i=id.fi,j=id.se;
            up(i,j);
            ans=max(ans,dp[i][j]);
        }
        // cout<<v<<el;
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}