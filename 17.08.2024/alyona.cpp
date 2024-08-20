#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()

#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 2e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n ; 
vii g[MAXN] ;
int a[MAXN] , h[MAXN] , f[MAXN] ;
vi V ; 

void dfs(int u,int par) {
	V.pb(u) ;
	if(V.size() > 2) { 
		int l = 1 , r = V.size() - 1 , res = V.size() - 1 ; 
		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if(h[u] - h[V[mid]] <= a[u]) res = mid , r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		f[V[res-1]]-- ; 
		f[V[V.size()-2]]++ ;
	}
	for(auto x : g[u]) {
		int v = x.fi , w = x.se ; 
		if(v==par) continue ;
		h[v] = h[u] + w ;
		dfs(v,u) ; 
	}
	V.pop_back() ; 
}

void calc(int u,int par) {
	for(auto [v,w] : g[u]) {
		if(v==par) continue ; 
		calc(v,u) ; 
		f[u]+= f[v] ; 
	} 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }	
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ;
    FOR(i,1,n-1) {
    	int u , v , w ; cin >> u >> v >> w ; 
    	g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
    }
    V.pb(0) ;
    dfs(1,1) ;
    calc(1,1) ;
    FOR(i,1,n) cout << f[i] << ' ' ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}