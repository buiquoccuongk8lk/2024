/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}

int n,k ; 
vii G[N] ; 
int h[N] , vis[N] ;
struct edge {
	int u ; 
	int v ; 
	int w ; 
}Edge[N] ; 
vi g[N] ; 
int len = 0 ;
vi tree ; 

void DFS(int u) {
	vis[u] = 1 ; 
	tree.pb(u) ; 
	for(auto v : g[u]) {
		if(vis[v]) continue ; 
		h[v] = h[u] + 1 ; 
		len = max(len,h[v]) ; 
		vis[v] = 1 ; 
		//cout << u << " "<<v  << endl ; 
		DFS(v) ; 
	}
}


bool Check(int mid) {

	tree.clear() ; 
	rep(i,1,n) g[i].clear() , vis[i] = 0 , h[i] = 0 ;

	len = 0 ; 

	rep(i,1,mid) {
		g[Edge[i].u].push_back(Edge[i].v) ; 
		g[Edge[i].v].push_back(Edge[i].u) ; 
	}

	rep(i,1,n) {
		if(!vis[i]) {
			tree.clear() ; 
			h[i] = 1 ; 
			DFS(i) ; 
			int root = i ; 
			int maxi = 1 ; 
			for(auto x : tree) {
				if(h[x] > maxi) {
					maxi = h[x] ;
					root = x ; 
				}
			}
			for(auto x : tree) {
				h[x] = 0 ; 
				vis[x] = 0  ;
			}
			h[root] = 1 ;
			DFS(root) ; 
			if(len >= k) return 1;
		}
	}
	return len >= k ;
}

void solve(void) {
	if(k<=1) {
		cout << 0 ;
		return ;
	}
	sort(Edge+1,Edge+n,[](edge u,edge v) {
		return u.w < v.w ;
	}) ;
	int l = 1 ; 
	int r = n-1 ; 
	int ans = -1 ; 
	while(l <= r) {
		int mid = (l+r) >> 1 ; 
		if(Check(mid)) {
			ans = Edge[mid].w ;  
			r = mid - 1 ; 
		}else l = mid + 1 ; 
	}
	cout << (ans==-1?-1:ans+100) ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> k ;
    rep(i,1,n-1) {
    	int u,v,w; 
    	cin >> u >> v >> w;
    	Edge[i].u = u ; 
    	Edge[i].v = v ; 
    	Edge[i].w = w ; 
    	G[u].pb({v,w}) ; 	
    	G[v].pb({u,w}) ; 
    }
    solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}