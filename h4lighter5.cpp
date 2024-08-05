/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define         ll long long 
#define         fi first
#define         se second
#define         pb push_back
#define         ii pair<int,int>
#define         vii vector<ii>
#define         vi vector<int>
#define         endl '\n' 
#define         sz(a) (int)a.size()
#define         all(a) a.begin(),a.end()
#define         FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define         FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define         FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define         uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e5 + 5 ;
const int LO = 17 ;
const int S = sqrt(N) + 1 ; 
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m , q ; 
vii g[N] ; 
int ans ;

void init() {
	cin >> n >> m >> q ; 
	FOR(i,1,m) {
		int u , v , c ; cin >> u >> v >> c ; 
		g[u].pb({v,c}) ; g[v].pb({u,c}) ; 
		ans+= (c == 1) ; 
	}
}

namespace sub1 {
	int color[5005][5005] ; 
	void solve() {
		FOR(u,1,n) {
			for(auto [v,w] : g[u]) {
				color[u][v] = w ; 
 			}
		}
		while(q--) {
			int u ; cin >> u ; 
			for(auto [v,w] : g[u]) {
				if(color[u][v] == 0) {
					ans++ ; 
					color[u][v] = 1 ; 
					color[v][u] = 1 ; 
				} else if(color[u][v] == 1) {
					ans-- ;
					color[u][v] = 0 ;
					color[v][u] = 0 ;
				}
			}
			cout << ans << ' ' ;
		}
	}
}

namespace sub2 {
	// A : chứa những đỉnh có bậc <= sqrt(N) 
	// B : chứa các đỉnh có bậc > sqrt(N)
	// f[u] : số lượng cạnh màu xanh liên thuộc u 
	int deg[N] , f[N] , d[N] ;
	vii g_bi[N] ;

	void trau(int u) {
		d[u]++ ; 
		for(auto [v,w] : g[u]) {
			int cl = w ; 
			if((d[u] + d[v])&1) cl = 1 - cl ; 
			if(cl==1) {
				ans++ ; 
				if(deg[v] > S) f[v]++ ;  
			} else {
				ans-- ; 
				if(deg[v] > S) f[v]-- ; 
			}
		}
	}

	void SP(int u) {
		d[u]++ ; 
		ans = ans - f[u] + deg[u] - f[u] ; 
		f[u] = deg[u] - f[u] ; 
		for(auto [v,w] : g_bi[u]) {
			int cl = w ; 
			if((d[u] + d[v])&1) cl = 1 - cl ; 
			if(cl==1) f[v]++ ; 
			else f[v]-- ; 
		}
	}

	void solve() {
		FOR(i,1,n) deg[i] = sz(g[i]) ; 	

		FOR(i,1,n) {
			int cnt = 0 ; 
			for(auto [v,w] : g[i]) cnt+=(w==1) ; 
			f[i] = cnt ; 
		}
		
		FOR(i,1,n) if(deg[i] > S) {
			for(auto [v,w] : g[i]) {
				if(deg[v] > S) g_bi[i].pb({v,w}) ; 
			}
		}

		while(q--) {
			int u ; cin >> u ; 
			if(deg[u] <= 300) trau(u) ; 
			else SP(u) ; 
			cout << ans << ' ' ; 
		}
		
	}
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; 
    //if(n <= 5000 && q <= 5000) sub1::solve() ;
    sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}