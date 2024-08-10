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
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int S , n ; 
int a[(int)25] ;
void init(void) {
	cin >> S >> n ;
	rep(i,1,n) cin >> a[i] ; 
}

namespace sub {
	int ans = 0 ;
	int dp[5005][5005] ; 
	int calc(int sum ,int pref_sum) {
		if(pref_sum == S) return 0; 
		if(dp[sum][pref_sum]!=-inf) return dp[sum][pref_sum] ; 
		dp[sum][pref_sum] = -inf ; 
		rep(i,1,n) {
			if(sum + pref_sum + a[i] <= S) dp[sum][pref_sum] = max(dp[sum][pref_sum] , a[i] + calc(sum + a[i] , sum + pref_sum + a[i]) ) ; 
		}
		return dp[sum][pref_sum] ;
	}
    void solve(void) {
    	rep(i,0,5e3) rep(j,0,5e3) dp[i][j] = -inf ; 
    	 cout << (calc(0,0) < 0 ?-1 : calc(0,0) ) ; 
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