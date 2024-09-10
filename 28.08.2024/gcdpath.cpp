// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 2e6 + 5 ;

int n ;
int a[MAXN] ;
vi g[MAXN] ;
vi z[MAXN] ;
ii e[MAXN] ;

void init() {
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,n-1) {
        int u , v ; cin >> u >> v ; 
        e[i] = {u,v} ;
        z[__gcd(a[u],a[v])].pb(i) ;
    }
}

int cnt = 0 ; 
int vis[MAXN] ;
void dfs(int u) {
    cnt++ ;
    vis[u] = 1 ;
    for(auto v : g[u]) {
        if(vis[v]) continue ; 
        dfs(v) ;
    }
}

ll f[MAXN] ; 

void solve() {
    ll ans = 0 ;    
    int mx = *max_element(a+1,a+1+n) ; 

    FORD(i,mx,1) {
        for(int j = i ; j <= mx ; j+=i) {
            for(auto id : z[j]) {
                g[e[id].fi].clear() ; 
                g[e[id].se].clear() ; 
                vis[e[id].fi] = 0 ; 
                vis[e[id].se] = 0 ;
            }
        }
        for(int j = i ; j <= mx ; j+=i) {
            for(auto id : z[j]) {
                g[e[id].fi].pb(e[id].se) ; 
                g[e[id].se].pb(e[id].fi) ; 
            }
        }
        for(int j = i ; j <= mx ; j+=i) {
            for(auto id : z[j]) {
                if(!vis[e[id].fi]) {
                    cnt = 0 ; 
                    dfs(e[id].fi) ; 
                    f[i]+= 1ll * cnt * (cnt - 1) / 2 ;
                } 
                if(!vis[e[id].se]) {
                    cnt = 0 ; 
                    dfs(e[id].se) ; 
                    f[i]+= 1ll * cnt * (cnt - 1) / 2 ;
                }
            }
        }
        for(int j = 2 * i ; j <= mx ; j+=i) f[i] -= f[j] ; 
    }
    
    FOR(j,1,mx) ans+= 1ll * f[j] * j ;
    cout << ans ; 
}

signed main() {
    #define task "gcdpath"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int t ; cin >> t ;
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */