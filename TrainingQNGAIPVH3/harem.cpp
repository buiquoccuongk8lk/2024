/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 3e5 + 5 ;

int n , m ;
vii g[N] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u , v ; cin >> u >> v ; 
		g[u].emplace_back(make_pair(v,i)) ; 
	}
}

vector <int> topo ; 
bool vis[N] ;

void dfs(int u) {
    vis[u] = 1 ; 
    for(pair<int,int> x : g[u]) {
        int v = x.fi ;
        if(vis[v]) continue ; 
        dfs(v) ; 
    }
    topo.push_back(u) ; 
}

void solve() {
    FOR(i,1,n) if(!vis[i]) dfs(i) ; 
    reverse(all(topo)) ; 
    int res = 0 ; 
    FOR(i,0,topo.size()-2) {
        bool ok = false ;
        int u = topo[i] ;
        for(pair<int,int> x : g[u]) {
            int v = x.fi , w = x.se ; 
            if(v == topo[i + 1]) {
                ok = true ; 
                maxi(res,w) ;
            }
        }
        if(!ok) {
            cout << - 1 ; 
            return ; 
        }
    }
    cout << res << endl ;   
    for(int x : topo) cout << x << ' ' ; 
}

signed main() {
    #define task "harem"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 