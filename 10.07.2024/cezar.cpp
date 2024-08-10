#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e4 + 5 ;
const int oo = 2e9 ; 
const int LO = __lg(maxn) + 1 ;

int n,k ; 
vector<int> g[maxn] ;
int P[maxn][LO],h[maxn],f[maxn],d[maxn],mark[maxn],par[maxn] ; 

void init(void) {
	cin >> n >> k ; 
	FOR(i,1,n-1) {
		int u,v ; 
		cin >> u >> v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
namespace sub1 {
	int child[maxn];   
	void countChild(int u, int parent) {
	    child[u] = 1;
	    for (int v : g[u]) { 
	        if (v!=parent) { 
	            countChild(v, u);
	            child[u] += child[v];
	        }
	    }
	}
	int findCentroid(int u, int parent) {
	    for (int v : g[u]) {
	        if (v!=parent) {
	            if (child[v] > n/2) { 
	                return findCentroid(v, u);
	            }
	        }
	    }
	    return u;
	}
	void dfs(int u,int par) {
		for(auto v : g[u]) {
			if(v==par) continue ; 
			h[v] = h[u] + 1 ; 
			P[v][0] = u ;
			dfs(v,u) ; 
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

	void solve(void) {
		countChild(1,1) ; 
		int centroid = findCentroid(1,1) ;
		dfs(1,1) ;	

		for(int j(1) ; (1<<j) <= n ; j++) {
			FOR(i,1,n) {
				P[i][j] = P[P[i][j-1]][j-1] ; 
			}
		}

		int ans = oo ;  

		FOR(i,centroid,centroid) {
			FOR(j,1,n) f[j] = d[j] = mark[j] = 0 ; 
			FOR(j,1,n) if(i!=j) {
				f[j]++ ; 
				f[i]++ ; 
				int cha = LCA(i,j) ; 
				f[cha]-=2 ; 
				d[cha]++ ; 
			}
			function<void(int,int)>dfs1 = [&](int u,int par) {
				for(auto v : g[u]) {
					if(v==par) continue ; 
					dfs1(v,u) ; 
					f[u]+=f[v] ; 
				}
			} ; 
			dfs1(1,1) ; 
			set<pair<int,int>>se ; 
			FOR(j,1,n) if(i!=j) {
				se.insert({f[j] + d[j],j}) ; 
			}
			FOR(j,1,k) if(!se.empty()) {
				pair<int,int> val = *(se).rbegin() ; 
				se.erase(val) ;
				mark[val.second] = 1 ; 
			}
			FOR(j,1,n) f[j] = oo ; 
			f[i] = 0 ; 
			deque<int> dq ; 
			dq.pb(i) ;
			while(!dq.empty()) {
				int u = dq.front() ; 
				dq.pop_front() ; 
				for(auto v : g[u]) {
					if(mark[v]==1 && f[v] > f[u]) {
						f[v] = f[u] ; 
						dq.push_front(v) ; 
					} else if(f[v] > f[u] + 1) {
						f[v] = f[u] + 1 ; 
						dq.pb(v) ; 
					}
				}
			}
			int sum = 0 ;
			FOR(j,1,n) sum+=f[j] ; 
			ans = min(ans,sum) ; 
		}

		cout << ans ;
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
    sub1::solve() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}