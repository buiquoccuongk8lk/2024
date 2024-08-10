/// никогда не сдавайся

#include <bits/stdc++.h>
using namespace std ; 
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 
#define fi first
#define se second

const int N = 3e5 + 5 ;

int n , stA , stB ;
vector<int> g[N] ;
int f[N] , dd[N] , ra[N] , rb[N] , cha[N] , h[N] ;
vector<int> v ;

void init(void) {
	cin >> n ; 
	int u , v ; 
	FOR(i,1,n-1) {
		cin >> u >> v ; 
		g[u].push_back(v) ; g[v].push_back(u) ; 
	}
	cin >> stA >> stB ; 
}

void dfs1(int u,int par) {
	for(auto v : g[u]) {
		if(v==par) continue ; 
		h[v] = h[u] + 1 ;
		cha[v] = u ;
		dfs1(v,u) ; 	
		if(!dd[v]) f[u] = max(f[u],f[v]+1) ; 
		else dd[u] = 1 ; 
	}
}

void solve(void) {	
	dd[stB] = 1 ; 
	f[stB] = -2e9 ; 
	dfs1(stA,stA) ; 	
	for(int u = stB ; u ; u = cha[u]) {
		v.push_back(u) ; 
	}	
	int ans = 0 ;
	int m = v.size() ;  
	FORD(i,m-1,0) {
		ra[i] = f[v[i]] - i + m - 1 ;
		if(i < m - 1) ra[i] = max(ra[i] , ra[i+1]) ; 
	}
	FOR(i,0,m-1) {
		rb[i] = i + f[v[i]] ; 
		if(i) rb[i] = max(rb[i],rb[i-1]) ;
	}
	FOR(i,0,m-1) ans = max(ans , min( ra[i] , rb[i-1] ) + 1) ; 
	cout << ans ;
}	


signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}