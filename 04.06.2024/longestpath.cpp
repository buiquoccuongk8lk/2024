/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const ll inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , m ;
vi G[N] ;
void init(void) {
	cin >> n >> m ;
	rep(i,1,m) {
		int u,v ; 
		cin >> u >> v ;
		G[u].pb(v) ; 
	}
}
int dp[N] , vis[N] ; 
void dfs(int u,int par) {
	vis[u] = 1 ; 
	for(auto v : G[u]) {
		if(v==par) continue ; 
		if(vis[v]) maximize(dp[u],dp[v] + 1) ; 
		else {
			dfs(v,u) ; 
			maximize(dp[u],dp[v] + 1) ; 
		}
	}
}
void solve(void) {
	rep(i,1,n) {
		dfs(i,i) ; 
	}
	cout << *max_element(dp+1,dp+1+n); 
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
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}