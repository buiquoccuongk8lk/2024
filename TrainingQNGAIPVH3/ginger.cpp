/* 29 . 03 . 2008 */
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
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

const int N = 2e5 + 5 ;

int n , m , A ;
struct Edges {
    int u , v , w , id ;
} e[(int)2e5+5] ;
struct KE {
    int v , w , id ;
} ;
vector<KE> g[(int)1e5+5] ; 
int dist[(int)1e5+5] ; 
ii cha[(int)1e5+5] ;
int ee[(int)2e5+5] ;

void init() {
    cin >> n >> m >> A ;
    FOR(i,1,m) cin >> e[i].u >> e[i].v >> e[i].w , e[i].id = i ;
    sort(e+1,e+1+m,[](Edges u,Edges v) {
        return u.w < v.w ;
    }) ;
}

struct DisjoinSet {
    int par[(int)1e5+5] ;
    int acs(int u) {
        if(par[u] < 0) return u ;
        else return par[u] = acs(par[u]) ; 
    }
    bool join(int u,int v) {
        int x = acs(u) , y = acs(v) ;
        if(x == y) return 0 ;
        if(par[x]>par[y])swap(x,y) ; 
        par[x]+= par[y] ; 
        par[y] = x ; 
        return 1 ;
    }
} dsu ;

void dfs(int u,int ed,int par) {
	if(u == ed) return ; 
	for(auto [v , w , id] : g[u]) {
		if(v==par) continue ; 
		cha[v] = {u , id} ; 
		dist[v] = dist[u] + 1 ; 
		dfs(v,ed,u) ; 
	}
}

void solve() {
    FOR(i,1,n) dsu.par[i] = -1 ;

    FOR(i,1,m) {
        if(dsu.join(e[i].u,e[i].v)) {
            g[e[i].u].pb({e[i].v , e[i].w , e[i].id}) ; 
            g[e[i].v].pb({e[i].u , e[i].w , e[i].id}) ; 
        } else {    
            dfs(e[i].u,e[i].v,e[i].u) ; 
            int L = dist[e[i].v] ;
            cout << 1ll * e[i].w * e[i].w + 1ll * (L + 1) * A << endl ;

            cout << e[i].v << ' ' << L + 1 << endl ;

      		do {
      			cout << cha[e[i].v].second << ' ' ; 
      			e[i].v = cha[e[i].v].first ; 
      		} while(e[i].v!=e[i].u) ; 	

      		cout << e[i].id ;
      		return ; 
        }   
    }
    cout << "Poor girl" ; 
}

signed main() {
    #define task "ginger"
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
