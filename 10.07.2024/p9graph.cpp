#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 5e5 + 5 ;
const long long inf = 1e18 ;

template<class X,class Y> bool minimize(X &x,const Y &y) {
	if(x > y) {
		x = y ; 
		return true ; 
	} else return false ; 
}

int n,m ;
vector<int> g[maxn],revg[maxn] ;

void init(void) {	
	cin >> n >> m ; 
	//cout << n << ' ' << m << endl ; 	
	FOR(i,1,m) {
		int u,v ; 
		cin >> u >> v ; 
		g[u].pb(v) ; 
		revg[v].pb(u) ; 
		//cout << u << ' ' << v << endl ; 
	}
}

struct p9graph {
	int u , tt ;
	ll sum ; 
	bool operator <(const p9graph &x) const {
		return sum > x.sum ; 
	}
};
ll dist[maxn][4] ; 
pair<int,int> trace[maxn][3] ;

void solve(void) {
	#define fi first
	#define se second

	FOR(i,1,n) {
		FOR(tt,0,2) dist[i][tt] = inf ; 
	}

	priority_queue<p9graph,vector<p9graph>>pq ; 
	dist[1][0] = 0 ;
	pq.push({1 , 0 , 0}) ;

	while(!pq.empty()) {
		int u = pq.top().u ; 
		int tt = pq.top().tt ; 
		ll cost = pq.top().sum ; 
		pq.pop() ; 
		if(cost > dist[u][tt]) continue ; 	
		if(tt==0) {
			FOR(ntt,0,2) {
				//if(ntt==0 and tt!=0) continue ; 
				if(minimize(dist[u][ntt],dist[u][tt] + 1)) {
					pq.push({u , ntt , dist[u][ntt]}) ; 
					trace[u][ntt] = {u,tt} ; 
				}
			}
		}
		if(tt==0) {
			for(auto v : g[u]) {
				if(minimize(dist[v][0],dist[u][0])) {
					pq.push({v , 0 , dist[v][0]}) ; 
					trace[v][0] = {u,0} ; 
				}
			}
			for(auto v : revg[u]) {
				if(minimize(dist[v][2],dist[u][0] + 1)) {
					pq.push({v , 2 , dist[v][2]}) ; 
					trace[v][2] = {u,0} ;
				}
			}
		}	
		if(tt==1) {
			for(auto v : g[u]) {
				if(minimize(dist[v][0],dist[u][1])) {
					pq.push({v , 0 , dist[v][0]}) ; 
					trace[v][0] = {u,1} ;
				}
			}
			for(auto v : revg[u]) {
				if(minimize(dist[v][0],dist[u][1])) {
					pq.push({v , 0 , dist[v][0]}) ; 
					trace[v][0] = {u,1} ;
				}
			}
		}
		if(tt==2) {
			for(auto v : g[u]) {
				if(minimize(dist[v][2],dist[u][2] + 1)) {
					pq.push({v , 2 , dist[v][2]}) ; 
					trace[v][2] = {u,2} ; 
				}
			}
			for(auto v : revg[u]) {
				if(minimize(dist[v][2],dist[u][2] + 1)) {
					pq.push({v , 2 , dist[v][2]}) ; 
					trace[v][2] = {u,2} ;
				}
			}
		}
	}
	int bestTT = 0 ; 
	ll ans = inf ; 
	FOR(tt,0,2) if(minimize(ans,dist[n][tt])) bestTT = tt ; 
	//cout << ans ; 
	while(1) {	
		if(n==0) break ; 
		cout << n << ' ' << bestTT << '-' << trace[n][bestTT].fi << ' ' << trace[n][bestTT].se << ' ' << dist[n][bestTT] << endl ;
		int tmp = n ; 
		n = trace[n][bestTT].fi ;
		bestTT = trace[tmp][bestTT].se  ; 
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
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}