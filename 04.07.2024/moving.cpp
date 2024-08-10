#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

template<class X,class Y> bool minimize(X&x,const Y&y) {
	if(x > y) {
		x = y ; 
		return 1 ; 
	} else return 0 ; 
}

const int maxn = 1e5 + 5 ;
const ll inf = 1e18 ; 

int n , m ; 
struct ke {
	int v , w ; 
} ; 
vector<ke> g[maxn] , revg[maxn] ; 

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,m) {
		int u,v,w ; cin >> u >> v >> w ; 
		g[u].push_back({v,w}) ;
		revg[v].push_back({u,w}) ;  
	}
}

ll dist[maxn][3] ;
struct node {
	int u ; ll cost ; int dir ; 
	bool operator <(const node &e) const {
		return cost > e.cost ; 
	}
} ;
void process(void) {
	FOR(i,1,n) dist[i][1] = dist[i][2] = inf ; 	
	priority_queue<node,vector<node>>pq ; 
	dist[1][1] = dist[1][2] = 0 ; 
	pq.push({1 , 0 , 1}) ; 
	while(!pq.empty()) {
		auto [u,cost,dir] = pq.top() ; 
		pq.pop() ; 
		if(cost > dist[u][dir]) continue ; 
		if(dir==1) {
			for(auto [v,w] : g[u]) {
				if(minimize(dist[v][1],dist[u][1] + w)) {
					pq.push({v , dist[v][1] , 1}) ; 
				}
			}
		}
		for(auto [v,w] : revg[u]) {
			if(minimize(dist[v][2],dist[u][dir] + w)) {
				pq.push({v , dist[v][2] , 2}) ; 
			}
		}
	}	
	FOR(i,2,n) {
		cout << ( min(dist[i][1],dist[i][2]) >= inf ? -1 : min(dist[i][1],dist[i][2])) << ' ' ;
	}
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; process() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}