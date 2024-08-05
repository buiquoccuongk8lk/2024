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

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ; 
vi G[N] ;
int deg[N] ; 

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u , v ; 
		cin >> u >> v ;
		G[u].pb(v) ; 
		G[v].pb(u) ; 
		deg[u]++ ;deg[v]++ ; 
	}
}

int par[N] , sz[N] ; 

void init_DSU(void) {
	for(int i(1) ; i <= n ; i++) par[i] = i , sz[i] = 1 ; 
}

int acs(int u){
	if(par[u]==u) return u ; 
	return par[u] = acs(par[u]) ; 
}

void joint(int u,int v) {
	int x = acs(u) ; 
	int y = acs(v) ;
	if(x!=y) {
		par[x] = y ;
		sz[y]+=sz[x] ; 
	}
}

vector<int> DEG,NODE ; 
bool isDel[N] ; 

void process(void) {
    
	ll ans = 0 ; 

	set<ii> se_deg ; 

	init_DSU() ; 

	FOR(i,1,n) {
		se_deg.insert({deg[i] , i}) ; 
	}

	//FOR(i,1,n) cout << deg[i] << ' ' ;

	FOR(i,1,n) {
		auto it = *se_deg.begin() ; 
		int node = it.se ; 
		int val = it.fi ; 
		DEG.pb(val) ; 
		NODE.pb(node) ; 
		//cout << node << ' ' << val << endl ;
		isDel[node] = 1 ; 
		se_deg.erase(it) ; 

		for(auto v : G[node]) {
			if(isDel[v]==0) {
				se_deg.erase({deg[v] , v}) ; 
				deg[v]-- ; 
				se_deg.insert({deg[v] , v }) ; 
			}
		}	

	}

	reverse(all(DEG)) ; 
	reverse(all(NODE)) ; 

	FOR(i,1,n) isDel[i] = 0 ; 

	FOR(i,0,sz(DEG)-1) {

		int u = NODE[i]  ; 
		int numDeg = DEG[i] ; 
		isDel[u] = 1 ; 

		for(auto v : G[u]) {
			if(isDel[v]) {
				if(acs(v)!=acs(u)) {
					joint(u,v) ;
				}
			}
		}

		maximize(ans , numDeg * sz[acs(u)] ) ; 
	}		

	cout << ans ; 

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}