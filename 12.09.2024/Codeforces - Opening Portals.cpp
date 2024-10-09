/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int n , m , k ; 
struct Edges {
	int u , v ;
	ll w ; 
	bool operator <(const Edges &e) const {
		return w < e.w ;
	}
}edges[N] ;
vii G[N] ; 
int spec_node[N] , nearest_node[N] ; 

void init(void) {
	cin >> n >> m ;
	FOR(i,1,m) {
		int u,v ; ll w ;
		cin >> u >> v >> w ; 
		edges[i].u = u , edges[i].v = v , edges[i].w = w ; 
		G[u].pb({v,w}) ; 
		G[v].pb({u,w}) ;
	}
	cin >> k ;
	FOR(i,1,k) cin >> spec_node[i] ; 
}

namespace sub {

	ll dist[N] ; 

	struct bg {
		int u ; 
		ll sum ; 
	} ;

	struct cmp {
		bool operator() (bg u, bg v) {
			return u.sum > v.sum ; 
		}
	} ; 

	void dijk(void) {

		priority_queue<bg,vector<bg>,cmp> pq ; 

		FOR(i,1,n) dist[i] = inf ; 

		FOR(i,1,k) {
			dist[spec_node[i]] = 0 ; 
			pq.push({spec_node[i] , 0}) ; 
			nearest_node[spec_node[i]] = spec_node[i] ; 
		}

		while(!pq.empty()) {
			int u = pq.top().u ; 
			ll cost = pq.top().sum ; 
			pq.pop() ; 
			if(cost > dist[u]) continue ; 
			for(auto x : G[u]) {
				int v = x.fi ; 
				ll w = x.se ; 
				if(minimize(dist[v] , dist[u] + w)) {
					nearest_node[v] = u ; 
					pq.push({v , dist[v]}) ;
				}
			}
		}

	}

	struct  {
		int n ; 
		vector<int> lab ; 
		void init(int n) {
			lab.resize(n + 1 , -1) ; 
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

	void solve(void) {

		dijk() ;

		FOR(i,1,m) {
			edges[i].w+= dist[edges[i].u] + dist[edges[i].v] ; 
			edges[i].u = nearest_node[edges[i].u] ; 
			edges[i].v = nearest_node[edges[i].v] ;
		}

		ll ans = dist[1] ; 

		dsu.init(n + 5) ;
		
		sort(edges+1,edges+1+m) ;

		FOR(i,1,m) {
			if(dsu.join(edges[i].u,edges[i].v)) {
				ans+= edges[i].w ; 
			}
		}

		cout << ans ;
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
    sub::solve() ;  
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}