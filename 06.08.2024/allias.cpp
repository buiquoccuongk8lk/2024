#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
using namespace std ; 
#define ii pair<int,int>
#define fi first
#define se second
const int N = 1e5 + 5 ;

int n , m , q ;
struct {
	string u ;
	string v ;
	int w ;
} e[N] ;
long long dist[1005][1005] ;
vector<pair<int,int>> g[1005] ;

void init() {
	cin >> n >> m ;
	for(int i(1) ; i <= m ; i++) cin >> e[i].u >> e[i].v >> e[i].w ; 
	cin >> q ; 
}

void solve() {
	map<string,int> mp , id ;
	for(int i(1) ; i <= m ; i++) {
		mp[e[i].u]++ ; 
		mp[e[i].v]++ ; 
	}
	int sz = 0 ;
	for(auto x : mp) {
		id[x.first] = ++sz ; 
	}

	for(int i(1) ; i <= m ; i++) {
		int u = id[e[i].u] , v = id[e[i].v] , w = e[i].w ; 
		g[u].push_back({v,w}) ; 
	}	

	for(int i(1) ; i <= n ; i++) {
		for(int j(1) ; j <= n ; j++) dist[i][j] = 1e18 ; 
		dist[i][i] = 0 ;
		priority_queue<ii,vector<ii>,greater<ii>>pq ; 
		pq.push({ 0 , i}) ; 
		while(!pq.empty()) {
			int u = pq.top().se ; 
			long long cost = pq.top().fi ;
			pq.pop() ; 
			if(cost > dist[i][u]) continue ; 
			for(auto [v,w] : g[u]) {
				if(dist[i][v] > cost + w) {
					dist[i][v] = cost + w ; 
					pq.push({cost + w , v}) ; 
				}
			}
		}
	}

	for(int i(1) ; i <= q ; i++) {
		string s , t ; 
		cin >> s >> t ; 
		int u = id[s] , v = id[t] ; 
		//cout << u << ' ' << v << endl;
		if(dist[u][v] < 1e18) {
			cout << dist[u][v] << '\n' ; 
		} else {
			cout << "Roger" << '\n' ; 
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
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}