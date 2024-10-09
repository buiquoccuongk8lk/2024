/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++)
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 5e5 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}

int n , q ;
vi G[N] ;
int a[N], inp[N],out[N],parent[N],f[N] ; 
int timeDFS = 0 ;
int ans = 0 ;
void DFS(int u,int par) {
	inp[u] = ++timeDFS ;
	for(auto v : G[u]) {
		if(v==par) continue ;
		parent[v] = u ;
        f[v]+=f[u] ; 
		DFS(v,u) ; 
	}
	out[u] = timeDFS ;
}
map<int,vector<int>> vec ; 
void push(int u,int par) {
    vec[f[u]].pb(inp[u]) ; 
    for(auto v : G[u]) {
        if(v==par) continue ; 
        push(v,u) ; 
    }
}
signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> q ;
    rep(i,1,n) cin >> a[i] ;
    rep(i,1,n-1) {
    	int u,v ;
    	cin >> u >> v ;
    	G[u].pb(v) ;
    	G[v].pb(u) ;
    }
    rep(i,1,n) f[i] = (a[i]==1?1:-1) ; 
    DFS(1,0) ;
    push(1,0) ; 
    while(q--) {
        int u ; 
        cin >> u ;
        int par = parent[u] ; 
        int l = lower_bound(vec[f[par]].begin(),vec[f[par]].end(),inp[u]) - vec[f[par]].begin() ;
        int r = upper_bound(vec[f[par]].begin(),vec[f[par]].end(),out[u]) - vec[f[par]].begin() ;
        cout << r - l << '\n' ;
    } 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}
