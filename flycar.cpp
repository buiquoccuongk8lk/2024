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

const int N = 400 + 5 , LO = 17 , base = 311 ;
const ll inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , k ;
ll a[N] ;

void init(void) {
	cin >> n >> k ;
	rep(i,1,n) {
		cin >> a[i] ; 
	}
}

namespace sub {
	ll dp[N][N] ;
	ll pre[N] ;
	int rmq[N][LO] ; 
	int get_max(int l,int r) {
		int K = log2(r-l+1) ;
		return max(rmq[l][K],rmq[r-(1<<K)+1][K]) ;
	}
    void solve(void) {
    	rep(i,0,n) rep(j,0,k) dp[i][j] = inf ; 
    	rep(j,0,k) dp[0][j] = 0 ;
    	rep(i,1,n) pre[i] = pre[i-1] + a[i] ; 
    	rep(j,0,k) dp[1][j] = 0 ;
    	rep(i,1,n) rmq[i][0] = a[i] ;
    	for(int j(1) ; (1<<j) <= n ; j++) {
    		for(int i(1) ; i +(1<<j) - 1 <= n ; i++) {
    			rmq[i][j] = max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
    		}
    	}
    	rep(i,1,n) {
    		dp[i][0] = get_max(1,i) * i - (pre[i]) ; 
    	}
    	rep(i,1,n) {
    		rep(j,1,k) {
    			rep(v,1,i) {
    				minimize(dp[i][j],dp[v-1][j-1] + get_max(v,i)*(i-v+1) - (pre[i]-pre[v-1]) ) ; 
    			}
    		}
    	}	
    	ll ans = inf ; 
    	rep(j,0,k) minimize(ans,dp[n][j]) ;
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