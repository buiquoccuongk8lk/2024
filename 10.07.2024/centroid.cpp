#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 3e5 + 5 ;
const int LO = __lg(maxn) + 1 ;

int n , m ; 
vector<int> g[maxn] ; 
int sz[maxn] ;
int root ;
int P[maxn][LO],h[maxn] ;

void init(void) {
	cin >> n >> m ;
	FOR(i,1,n) {
		int p ; 
		cin >> p ;
		if(p!=0) {
			//g[i].pb(p) ; 
			g[p].pb(i) ; 
		} else root = i ;
	}
}
	
void DFS(int u,int par) {
	sz[u] = 1 ; 
	for(auto v : g[u]) {
		if(v==par) continue ; 
		h[v] = h[u] + 1 ;
		P[v][0] = u ; 
		DFS(v,u) ; 
		sz[u]+=sz[v] ; 
	}
}

int findCentroid(int u,int par,int val) {
	for(auto v : g[u]) {
		if(v==par) continue ; 
		if(2 * sz[v] >= val) return findCentroid(v,u,val) ; 
	}
	return u ; 
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

int calc(int u,int v) {
	return h[u] + h[v] - 2*h[LCA(u,v)] ; 
}

void solve(void) {

	DFS(root,root) ;

	for(int j(1) ; (1<<j) <= n ; j++) {
		FOR(i,1,n) {
			P[i][j] = P[P[i][j-1]][j-1] ; 
		}
	}

	while(m--) {
		int u ; 
		cin >> u ;
		int val1 = sz[u] ; 
		int u1 = findCentroid(u,u,val1) ; 
		cout << u1 << ' ' ; 
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