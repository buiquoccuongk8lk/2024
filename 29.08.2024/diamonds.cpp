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
const int MAXN = 3e5 + 5 ;

int n , m ;
ii e[MAXN] ;
vii g[MAXN] ;
int c[MAXN] ;
ii deg[MAXN] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) cin >> e[i].fi >> e[i].se ; 
	FOR(i,1,m) {
		g[e[i].fi].pb(ii(e[i].se,i)) ; 
		g[e[i].se].pb(ii(e[i].fi,i)) ; 
	}
}

bool cmp(ii x,ii y){
	if(g[x.fi].size()==g[y.fi].size()) return x.fi<y.fi;
	else return g[x.fi].size()<g[y.fi].size();
}

void solve() {
	ll ans = 0 ; 
	FOR(u,1,n) {
		sort(all(g[u]),cmp) ;
	}
	FOR(u,1,n) {
		for(auto [v,id] : g[u]) deg[v] = {u , id} ; 
		for(auto l:g[u]) {
				int v=l.fi ;
				int id=l.se ;
				if(g[v].size()>g[u].size() or (g[v].size()==g[u].size() and v>u)) break;
				for(auto l1:g[v]) {
					int k=l1.fi;
					int id2=l1.se;
					if(g[k].size()>g[v].size() or (g[k].size()==g[v].size() and k>v)) break;
					if(deg[k].fi==u) {
						c[id]++;
						c[id2]++;
						int id1=deg[k].se;
						c[id1]++;
						ans-=3;
					}
				}
			}
	}

	FOR(i,1,m) {
		ans+= 1ll * c[i] * c[i] ;
	}
	cout << ans/2 ; 
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