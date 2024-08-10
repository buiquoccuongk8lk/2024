/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e5 + 5 ;
const int LO = __lg(N) + 1 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , q ; 
void init(void) {
	cin >> n >> q ; 
}

namespace sub1 {
	
	struct {
		vector<int> lab ; 
		int n ; 
		void init(int n) {
			lab.resize(n + 2 , -1) ; 
		}
		int find(int x) {
			return lab[x] < 0 ? x : find(lab[x]) ; 
		}
		bool join(int u,int v) {
			int x = find(u) ; int y = find(v) ; 
			if(x==y) return 0 ; 
			if(lab[x] > lab[y]) swap(x,y) ; 
			lab[x]+=lab[y] ; 
			lab[y] = x ;
			return 1 ; 
		}
	} dsu ;

	vii G[N] ; 
	int P[N][LO] , h[N] ; 
	ll f[N] , sum[N][LO] ;

	void solve(void) {

		vector<int> ques ;
		
		dsu.init(n + 2) ;

		FOR(i,1,q) {
			int type , u , v , w ; 
			cin >> type ; 
			if(type==1) {
				cin >> u >> v >> w ; 
				if(dsu.join(u,v)) {
					G[u].pb({v,w}) ; 
					G[v].pb({u,w}) ; 
				}
			} else {
				cin >> u ; 
				ques.pb(u) ; 
			}
		}

		function<void(int,int)> dfs = [&] (int u,int par) {
			for(auto [v,w] : G[u]) {
				if(v==par) continue ;
				P[v][0] = u ; 
				h[v] = h[u] + 1 ; 
				sum[v][0] = w ;
				f[v] = f[u] + w ;  
				dfs(v,u) ;
			}
		} ;

		dfs(1,1) ; 

		for(int j = 1 ; (1<<j) <= n ; j++) {
			FOR(i,1,n) {
				int x = P[i][j-1] ;
				P[i][j] = P[x][j-1] ; 
				sum[i][j] = sum[i][j-1] + sum[x][j-1] ; 
			}
		}

		auto get_sum = [&] (int u,int v) {
			if(h[u] < h[v]) swap(u,v) ; 
			int z = __lg(h[u]) ; 
			ll ret = 0 ;
			FORD(s,z,0) {
				if( (h[u] - h[v]) >= (1<<s) ) {
					ret+= sum[u][s] ; 
					u = P[u][s] ; 
				}
			}
			if(u==v) return ret ; 
			FORD(s,z,0) {
				if(P[u][s]!=P[v][s]) {
					ret+= sum[u][s] ;
					ret+= sum[v][s] ; 
					u = P[u][s] ; 
					v = P[v][s] ;
				}
			}
			ret+=sum[u][0] ; 
			ret+=sum[v][0] ; 
			return ret ; 
		} ;

		int node1 = -1 ; 
		int maxi = 0 ;

		FOR(i,1,n) {
			if(maximize(maxi , f[i])) {
				node1 = i ; 
			}
		}

		FOR(i,1,n) f[i] = 0 ;

		function<void(int,int)> dfs1 = [&] (int u,int par) {
			for(auto [v,w] : G[u]) {
				if(v==par) continue ; 
				f[v] = f[u] + w ; 
				dfs1(v,u)  ;
			}
		} ; 

		dfs1(node1,node1) ;

		maxi = 0 ;
		int node2 = -1 ; 
		FOR(i,1,n) {
			if(maximize(maxi , f[i])) {
				node2 = i ;
			}
		}

		for(auto u : ques) {
			cout << max( get_sum(u,node1) , get_sum(u,node2) ) << endl ;
		}

	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    sub1::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}