#define TASK "xayduong"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;

#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const int N = 3e5+5, oo = 2e9, LO = 15; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), EPS = 1e-9;

struct ke
{
    int  v ;
    ll w; 
}; 
struct query
{
    int T ; 
    int u ,v  ;
    ll w ; 
} ; 
int n , q ; 
int P[N][LO+3] ; 
ve<ke> g[N] ; 
int pa[N] ;
int h[N] ; 
ll W[N][LO+3] ;
query Q[N] ; 
void build_lca()
{
    FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1],W[i][j]=W[i][j-1]+W[P[i][j-1]][j-1] ; 
}
ll lca(int u ,int v)
{
    ll dis = 0 ; 
    if(h[u]<h[v])swap(u,v) ;  
    FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])dis+=W[u][i],u=P[u][i] ;
    if(u==v)return dis; 
    FORD(i,LO,0)
    {
        int nu = P[u][i] ; 
        int nv = P[v][i] ; 
        if(nu!=nv)
        {
            dis+=W[u][i]+W[v][i] ;          
            u=nu ; 
            v=nv ; 
        }
    }
    return dis+W[u][0]+W[v][0] ;
}  

int goc(int u )
{
    return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
void hop(int u ,int v)
{
    int nu = goc(u) ; 
    int nv = goc(v) ; 
    if(nu==nv)return ; 
    pa[nu]=nv ; 
}
void doc()
{
    cin>> n >> q ; 
}       
void dfs(int u ,int p)
{
    for(auto x : g[u])
    {
        int v = x.v ; 
        int w = x.w ;
        if(v==p)continue ; 
        P[v][0] = u ;
        h[v] = h[u]+1;  
        W[v][0] = w ; 
        dfs(v,u) ; 
    }
}
pll far[N] ; 
void ket_hop(int u ,int v,ll w)
{
    int chau = goc(u) ; 
    int chav = goc(v) ; 
    int x = far[chau].fi ; 
    int y = far[chau].se ; 
    int z = far[chav].fi ; 
    int t = far[chav].se ; 
    ll w1 = lca(x,y) ;  
    ll w2 = lca(z,t) ; 
    ll w3 = 0 ;  
    ll g1 = lca(x,u) ;
    ll g2 = lca(y,u) ;
    int d , e ; 
    if(g1>=g2)w3+=g1,d=x ; 
    else w3+= g2,d=y ;
    g1 = lca(z,v) ; 
    g2 = lca(t,v) ; 
    if(g1>=g2)w3+=g1,e=z ; 
    else w3+= g2,e=t ;
    w3+=w; 
    pa[chav]=chau ; 
    ll ma = max({w1,w2,w3}) ; 
    if(ma==w2)far[chau] = far[chav];
    else if(ma==w3)far[chau] = mp(d,e) ;  
}
void xuly()
{
    FOR(i,1,n)pa[i] = i ;  
    int cnt = 0 ; 
    while(q--)
    {
        int T ; cin>>T ; 
        int u ,v ; ll w ;
        if(T==1)
        {
            cin>>u>>v>>w ;
            int chau = goc(u) ; 
            int chav = goc(v) ; 
            if(chau!=chav)pa[chau]=chav , g[u].pb({v,w}) , g[v].pb({u,w}) , Q[++cnt] = {1,u,v,w} ; 
        }
        else cin>>u,Q[++cnt] = {2,u,0,0} ; 
    }
    dfs(1,0) ; 
    build_lca() ;
    FOR(i,1,n)pa[i] = i,far[i]=mp(i,i); 
    FOR(i,1,cnt)
    {
        int T = Q[i].T  ; 
        int u = Q[i].u ; 
        int v = Q[i].v ; 
        ll w = Q[i].w ; 
        if(T==1)
        {
            ket_hop(u,v,w) ; 
        }
        else
        {
            int chau = goc(u) ; 
            cout<<max(lca(u,far[chau].fi),lca(u,far[chau].se))<<el;
        }
    } 
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}
