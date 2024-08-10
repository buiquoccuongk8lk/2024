/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , K ; 
int a[N] ; 

void init(void) {
	cin >> n >> K ; 
	FOR(i,1,n) cin >> a[i] ; 
}
namespace sub1 {
	ll dp[305][305][160] ;

	ll calc(int i,int j,int k) { 
		if(k > K) return -inf ; 
		if(i >= j) {
			if(k==K) return 0 ; 
			else return -inf ; 
		}
		if(dp[i][j][k]!=-inf) return dp[i][j][k] ; 
		ll &val = dp[i][j][k] ; 
		val = 0 ;
		maximize(val, calc(i+2,j,k+1) + abs(a[i] - a[i+1]) ) ; 
		maximize(val, calc(i,j-2,k+1) + abs(a[j] - a[j-1]) ) ; 
		maximize(val, calc(i+1,j-1,k+1) + abs(a[i] - a[j]) ) ; 
		maximize(val, calc(i+1,j,k) ) ; 
		maximize(val, calc(i,j-1,k) ) ; 
		return val ; 
	}

	void solve(void) {
	    FOR(i,0,n) FOR(j,0,n) FOR(k,0,K) dp[i][j][k] = -inf ; 

	    cout << calc(1,n,0) ; 
	}
}
/*namespace sub2 {

	ll dp[305][305][2] ;

	void solve(void) {

		FOR(i,1,n) FOR(j,1,n) FOR(k,0,K) dp[i][i][k] = -inf ;

		dp[0][0][0] = 0 ; 
			
		FOR(r,1,n) {
			FOR(l,r-1,1) {
				//FOR(k,0,K) {
					ll &val = dp[l][r][k] ; 
					maximize(val , dp[l+1][r][k] ) ; 
					maximize(val , dp[l][r-1][k] ) ; 
					if(k >= 1) {
						maximize(val , dp[l+2][r][k-1] + abs(a[l] - a[l+1] ) ) ;  
						maximize(val , dp[l][r-1][k-1] + abs(a[r] - a[r-1] ) ) ; 
						maximize(val , dp[l+1][r-1][k-1] + abs(a[l] - a[r] ) )  ;  
					}
				//}
			}
		}

		cout << dp[1][n][K] ;
	}

}*/

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    sub1::solve() ; 
  //  sub2::solve() ;  
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}