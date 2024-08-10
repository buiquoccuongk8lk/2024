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
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 666013 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}
template<class X, class Y> void add(X &x, const Y &y) {x+=y ; if(x>=MOD) x-=MOD ;}

int n ;
vi G[N] ;
void init(void) {
	cin >> n ;
	rep(i,1,n-1) {
		int u,v ;
		cin >> u >> v ; 
		G[u].pb(v) ;
		G[v].pb(u) ; 
	}
}	

namespace sub {
	int fact[N] ; 
	int child[N] ;
	int ans = 1 ;
	int mul(int a,int b){
		return (a*b)%MOD ;
	}
	int LT(int x,int y) {
		if(y==0) return 1 ;
		if(y==1) return x ; 
		int c = LT(x,y/2) ; 
		if(y%2==1) return ( (c*c)%MOD * x)%MOD ; 
		else return (c*c)%MOD ; 
	}
	int C(int N,int k) {
		return mul( fact[N] , LT( mul(fact[N-k],fact[k] ) ,MOD-2 ) ) ;
	}
	void dfs(int u,int par) {
		for(auto v : G[u]) {
			if(v==par) continue ; 
			dfs(v,u) ; 
			child[u]+=child[v] ;
			ans = mul(ans , C(child[u],child[v]) ) ;
		}
		child[u]++ ;
	}
	void solve(void) {
		fact[0] = 1 ;
		rep(i,1,1e6) fact[i] = (fact[i-1] * i)%MOD ;
		dfs(1,1) ;
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
    sub::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}