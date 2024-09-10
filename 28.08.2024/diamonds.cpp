// 29 . 03 . 2008 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
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

const int MAXN = 3e5 + 5 ;

int n , m ; 
vi g[MAXN] ;
ii e[MAXN] ;
gp_hash_table <int,int> mp[MAXN] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u,v ; cin >> u >> v ;
		if(u > v) swap(u,v) ;  
		g[u].pb(v) ; g[v].pb(u) ; 
		e[i] = ii(u,v) ; 
		mp[u][v] = mp[v][u] = 1 ;
	}
}
	
void solve() {	
	ll ans = 0 ;
	int u , v , cnt ;
	FOR(i,1,m) {	
		u = e[i].fi , v = e[i].se , cnt = 0 ; 
		if(g[u].size() > g[v].size()) swap(u,v) ; 
		for(auto x : g[u]) if(x!=v) {
			if(mp[x][v]) cnt++ ; 
		}
		ans+= 1LL * cnt * (cnt - 1) / 2 ; 
	}
	cout << ans ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */