/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<ll,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 2e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m1 , m2 ;
int s , t ;  
struct Edges {
	int u , v , w ; 
} e1[N] , e2[N] ; 
vii g1[N] , g2[N] , gNewSang[N] , gNewToi[N] ; 
int sz = 0 ;
ll dist[N] ; 
ll d[2 * 1005][2*1005] ; 
int cnt = 0 ;

void dijk(int st,vii g[],int tt) {
	FOR(i,1,n)dist[i] = inf ; 
	priority_queue<ii,vector<ii>,greater<ii>>pq ;
	dist[st] = 0 ;
	pq.push({dist[st],st}) ; 
	while(!pq.empty()) {
		int u = pq.top().se ; 
		ll cost = pq.top().fi ; 
		pq.pop() ; 
		if(cost > dist[u]) continue ; 
		for(auto [v,w] : g[u]) {
			if(minimize(dist[v],dist[u] + w)) {
				pq.push({dist[v],v}) ; 
			}
		}
	}
	if(tt==1) {
		FOR(i,1,m1) {
			auto [u,v,w] = e1[i] ; 
			if(dist[u] > dist[v]) {
				gNewSang[u].pb({v,w}) ; 
			} else if(dist[v] > dist[u]) {
				gNewSang[v].pb({u,w}) ;
			}
		}
	} else {
		FOR(i,1,m2) {
			auto [u,v,w] = e2[i] ; 
			if(dist[u] > dist[v]) {
				gNewToi[u].pb({v,w}) ; 
			} else if(dist[v] > dist[u]) {
				gNewToi[v].pb({u,w}) ; 
			}
		}
	}
}

/*bool isCycle = 0 ; 
bool vis[N][3] ; 

void dfs(int u,int par,int tt,int l) {
	if(isCycle) {
		return ; 
	}
	if(l == n + 1)  {
		isCycle = 1 ; 
		return ; 
	}
	if(tt==0) {
		for(auto [v,w] : gNewSang[u]) {
			if(v==par) {
				isCycle = 1 ; 
				return ; 
			}
		}
		for(auto [v,w] : gNewSang[u]) {
			if(v!=par) {
				int nt = 1 - tt ; 
				d[v][nt] = max(d[v][nt],d[u][tt] + w) ; 
				dfs(v,u,nt,l+1) ; 
			}
		} 
	} else {
		for(auto [v,w] : gNewToi[u]) {
			if(v==par) {
				isCycle = 1 ; 
				return ; 
			}
		}
		for(auto [v,w] : gNewToi[u]) {
			if(v!=par) {
				int nt = 1 - tt ; 
				d[v][nt] = max(d[v][nt],d[u][tt] + w) ; 
				dfs(v,u,nt,l+1) ;  
			} else {
				isCycle = 1 ; 
				return ;
			}		
		}	
	}
	vis[u][tt] = 1 ; 
}*/

void solve() {
	dijk(t,g1,1) ;
	dijk(t,g2,2) ; 	
//	dfs(s,0,0,0) ; 	
	memset(d,-1,sizeof d) ; 
	d[0][s] = 0 ;
	FOR(k,0,2*n-1) {
		if(k%2==0) {
			FOR(u,1,n) {
				if(d[k][u]!=-1) {
					for(auto [v,w] : gNewSang[u]) {
						maximize(d[k+1][v],d[k][u] + w) ;
					}
				}
			}
		} else {
			FOR(u,1,n) {
				if(d[k][u]!=-1) {
					for(auto [v,w] : gNewToi[u]) {
						maximize(d[k+1][v],d[k][u] + w) ;
					}
				}
			}
		}
	}
	ll ans = -1 ;
	FOR(i,1,n) {
		if(d[2*n][i]!=-1) {
			cout << - 1 ; 
			return ; 
		}
	}
	FOR(k,0,2*n-1) ans = max(ans,d[k][t]) ; 
	cout << ans ; 
} 

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n >> s >> t ;
    cin >> m1 ; 
    FOR(i,1,m1) {
    	int u , v , w ; 
    	cin >> u >> v >> w ; 
    	e1[i] = {u,v,w} ; 
    	g1[u].pb({v,w}) ; 
    	g1[v].pb({u,w}) ; 
    }
    cin >> m2 ;  
    FOR(i,1,m2) {
    	int u , v , w ; 
    	cin >> u >> v >> w ; 
    	e2[i] = {u,v,w} ; 
    	g2[u].pb({v,w}) ; 
    	g2[v].pb({u,w}) ; 
    }
   	solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}