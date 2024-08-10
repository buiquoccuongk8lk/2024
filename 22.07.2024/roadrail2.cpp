/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
#define MAX (int)1e3 + 5 
const long long inf = (long long)1e18 ;
#define int long long 

int numCity,numRoad,numRail,numQuery ; 
struct KE {
	int v , w , t ; 
} ; 
vector<KE> g[MAX] ; 

void init(void) {
	cin >> numCity >> numRoad >> numRail >> numQuery ; 
	for(int i = 1 ; i <= numRoad ; i++) {
		int u,v,w ; cin >> u >> v >> w ; u++ ; v++ ; 
		g[u].push_back({v,w,1}) ; 
	}
	for(int i = 1 ; i <= numRail ; i++) {
		int u,v,w ; cin >> u >> v >> w ; u++ ; v++ ; 
		g[u].push_back({v,w,2}) ; 
	}
}

namespace sub1 {
	struct PQ {
		int u , t ; long long cost ; 
		bool operator <(const PQ &e) const {
			return cost > e.cost ; 
		}
	} ; 
	long long dist[MAX][4] ; 
	void solve(void) {	
		while(numQuery--) {
			int cap , C ; 
			priority_queue<PQ,vector<PQ>>pq ; 
			cin >> C >> cap ; cap++ ; 
			for(int i = 1 ; i <= numCity ; i++) {
				dist[i][0] = dist[i][1] = dist[i][2] = inf ; 
			}
			dist[1][0] = 0 ; 
			pq.push({1,0,0}) ; 
			while(!pq.empty()) {
				int u = pq.top().u ;
				int t = pq.top().t ;
				long long cost = pq.top().cost ; 
				if(u==cap) break ; 
				pq.pop() ; 
				if(cost > dist[u][t]) continue ; 
				for(auto x : g[u]) {
					int v = x.v ; 
					int w = x.w ; 
					int t_new = x.t ; 
					if(t==0) {
						if(dist[v][t_new] > dist[u][0] + w) {
							dist[v][t_new] = dist[u][0] + w ; 
							pq.push({v,t_new,dist[v][t_new]}) ; 
						}
					} else {
						w+= (t_new != t) * C ; 
						if(dist[v][t_new] > dist[u][t] + w) {
							dist[v][t_new] = dist[u][t] + w ; 
							pq.push({v,t_new,dist[v][t_new]}) ; 
						}
					}
				}
			}	
			long long ans = min({dist[cap][0],dist[cap][1],dist[cap][2]}) ; 
			if(ans >= inf) cout << -1 ; 
			else cout << ans ;
			cout << '\n' ;   
		}
	}
}

namespace sub2 {
	struct PQ {
		int u , sl , t ; long long cost ; 
		bool operator <(const PQ &e) const {
			return cost > e.cost ; 
		}
	} ; 
	long long dist[MAX][MAX][4] ; 

	void solve(void) {
		for(int i = 1 ; i <= numCity ; i++) for(int sl = 0 ; sl <= numCity ; sl++) {
			for(int t = 1 ; t <= 2 ; t++) dist[i][sl][t] = inf ; 
		}
		priority_queue<PQ,vector<PQ>>pq ; 
		pq.push({1 , 0 , 1 , dist[1][0][1] = 0}) ; 
		pq.push({1 , 0 , 2 , dist[1][0][2] = 0}) ; 
		while(!pq.empty()) {
			int u = pq.top().u ; int sl = pq.top().sl ; int t = pq.top().t ; long long cost = pq.top().cost ; 
			pq.pop() ;
			if(cost > dist[u][sl][t]) continue ; 
			for(auto x : g[u]) {
				int v = x.v ; int w = x.w ; int t_new = x.t ;
				if(sl + (t_new!=t) > numCity) continue ;  
				if(dist[v][sl + (t_new!=t)][t_new] > dist[u][sl][t] + w) {
					dist[v][sl + (t_new!=t)][t_new] = dist[u][sl][t] + w ; 
					pq.push({v , sl + (t_new!=t) , t_new , dist[v][sl + (t_new!=t)][t_new]}) ; 
				}
			}
		}
		while(numQuery--) {
			long long C ; int cap ; 
			cin >> C >> cap ; cap++ ; 
			long long ans = inf ; 
			for(int sl = 0 ; sl <= numCity ; sl++) {
				for(int t = 1 ; t <= 2 ; t++) {
					ans = min(ans , dist[cap][sl][t] + sl * C) ; 
				}
			}
			cout << (ans >= inf ? -1 : ans) << '\n' ; 
		}
	}

}

signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    init() ;
    if( numQuery <= 1000) sub1::solve() ; 
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}