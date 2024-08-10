#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;
const ll inf = 1e18 ;

struct EDGES {
	int u,v,w ; 
}e[maxn] ; 
int n,m ; 
int a[maxn] ;
vector<ii> g[maxn] ; 

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,n) cin >> a[i] ; 	
	FOR(i,1,m) {
		int u,v,w ; 
		cin >> u >> v >> w ; 
		g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
		e[i] = {u,v,w} ;  
	}
}

namespace sub1 {

	ll dist[maxn] ; 

	void solve(void) {

		FOR(i,1,n) FOR(j,i+1,n) {
			g[i].pb({j , (a[i] + a[j])/(__gcd(a[i],a[j]))}) ; 
			g[j].pb({i , (a[i] + a[j])/(__gcd(a[i],a[j]))}) ; 
		}

		priority_queue<ii,vector<ii>,greater<ii>>pq ; 

		FOR(i,1,n) dist[i] = inf ; 
		dist[1] = 0 ;
		pq.push({dist[1],1}) ; 
		while(!pq.empty()) {
			int u = pq.top().se ; 
			ll cost = pq.top().fi ;
			pq.pop() ; 
			if(cost > dist[u]) continue ; 
			for(auto [v,w] : g[u]) {
				if(dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w ; 
					pq.push({dist[v],v}) ; 
				}
			}
		}
		FOR(i,1,n) cout << dist[i] << ' ' ; 
	}
}

bool CheckSub2() {
	vector<int> vec ; 
	FOR(i,1,n) vec.pb(a[i]) ;
	sort(all(vec)) ; 
	int tmp = -1 ; 
	for(auto x : vec) {
		if(tmp!=-1 and x!=tmp) return 0 ;
		tmp = x ; 
	}
	return 1 ; 
}
namespace sub2 {

	set<ii> se[maxn] ;

	void solve(void) {

		FOR(i,1,m) {
			se[e[i].u].insert({e[i].v,e[i].w}) ; 
			se[e[i].v].insert({e[i].u,e[i].w}) ; 
		}

		FOR(i,1,n) {
			if(i==1) cout << 0 << ' ' ; 
			else {
				if(se[1].find({i,1})==se[1].end()) cout << 2 << ' ' ; 
				else cout << 1 << ' ' ;
			}
		}

	}

}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    init() ;
    if(n <= 1e3) sub1::solve() ;
    else if(CheckSub2()) sub2::solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}