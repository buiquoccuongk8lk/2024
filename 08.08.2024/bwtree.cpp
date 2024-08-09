#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 100005
const int sqrtN = 20 ;
const int LO = __lg(MAXN) + 1 ; 

int n , q ; 
int d[MAXN] ;
vector<int> black_node ;
vector<int> g[MAXN] ;
int is_black[MAXN] ;

struct {
	int P[MAXN][LO] , h[MAXN] ; 
	void dfs(int u,int par) {
		for(auto v : g[u]) if(v!=par) {
			h[v] = h[u] + 1 ; 
			P[v][0] = u ;
			dfs(v,u) ; 
		}
	}
	void init() {
		dfs(1,1) ; 
		for(int j(1) ; (1<<j) <= n ; j++) {
			FOR(i,1,n) {
				P[i][j] = P[P[i][j-1]][j-1] ; 
			}
		}
	}
	int LCA(int u,int v) {
		if(u==v) return u ; 
		if(h[u]<h[v]) swap(u,v) ; 
		int z = __lg(h[u]) ; 
		FORD(s,z,0) if((h[u]-h[v])>=(1<<s)) u = P[u][s] ; 
		if(u==v) return u ; 
		FORD(s,z,0) if(P[u][s]!=P[v][s]) {
			u = P[u][s] ; 
			v = P[v][s] ; 
		}
		return P[u][0] ; 
	}
	int dist(int u,int v) {
		return h[u] + h[v] - 2 * h[LCA(u,v)] ; 
	}
} lca ; 

void bfs(void) {
	queue<int> q ; 
	for(auto x : black_node) d[x] = 0 , q.push(x) ; 
	while(!q.empty()) {
		int u = q.front() ;
		q.pop() ; 
		for(auto v : g[u]) {
			if(mini(d[v],d[u]+1)) {
				q.push(v) ; 
			}
		}
	}
}

void solve() {
	FOR(i,1,n) d[i] = 2e9 ; 
	lca.init() ; 
	d[1] = 0 ;
	is_black[1] = 1 ;
	black_node.push_back(1) ; 
	FOR(i,0,q-1) {	
		if(i%sqrtN==0) {
			bfs() ; 
			black_node.clear() ; 
		}	
		int t , u ; cin >> t >> u ; 
		if(t==1) {
			is_black[u] = 1 ; 
			black_node.push_back(u) ; 
			d[u] = 0 ; 
		} else {	
			int mi = d[u] ; 
			if(mi!=0) for(auto x : black_node) mini(mi,lca.dist(x,u)) ; 
			cout << mi << '\n' ; 
		}
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> q ; 
    FOR(i,1,n-1) {
    	int u , v ; cin >> u >> v ; 
    	g[u].push_back(v) ; g[v].push_back(u) ; 
    }
    solve() ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}