#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;
int n,q ;
struct Edges {
	int u,v,w,id ; 
	bool operator <(const Edges &e) const {
		return w > e.w ; 
	}
} E[maxn] , Q[maxn] ; 

int par[maxn] , sz[maxn] ; 
int acs(int u) {return ( par[u] == u ) ? u : par[u] = acs(par[u]) ; }  
void join(int u,int v) {
	int x = acs(u) ; int y = acs(v) ; 
	if(x!=y) {
		par[y] = x ; 
		sz[x]+=sz[y] ;
	}
}
int ans[maxn] ; 

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> q ; 
    FOR(i,1,n-1) cin >> E[i].u >> E[i].v >> E[i].w ; 
    FOR(i,1,q) {
    	cin >> Q[i].w >> Q[i].v ; 
    	Q[i].id = i ;
    }
    sort(E+1,E+n) ; sort(Q+1,Q+1+q) ;
    FOR(i,1,n) par[i] = i , sz[i] = 1 ;  
    int j = 1 ;
    FOR(i,1,q) {
    	while(j <= n - 1 and E[j].w >= Q[i].w) {
    		join(E[j].u,E[j].v) ; 
    		j++ ; 
    	}
    	//cout << i << ' ' << j << endl ;
    	ans[Q[i].id] = sz[acs(Q[i].v)] ; 
    }
    FOR(i,1,q) cout << ans[i] - 1 << endl ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}