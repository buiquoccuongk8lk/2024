/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

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

int n,q,m ; 
int cost[205][205] ;
int a[N] ;

void init(void) {
	cin >> n >> m ; 
	FOR(i,1,n) FOR(j,1,n) cin >> cost[i][j] ;
	FOR(i,1,m) cin >> a[i] ; 
}

namespace sub1 {

	#define rep(i,a,b) for(int i(a) ; i <= b ; i++)
	#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
	#define repn(i,a,b) for(int i(a) ; i < b ; i++)

	int dp[55][55][55][55] ;

	void solve(void) {	
			
		rep(i,0,m) rep(t1,1,n) {
			rep(t2,1,n) rep(t3,1,n) {
				dp[i][t1][t2][t3] = oo ; 
			}
		}

		dp[0][1][2][3] = 0 ;
		dp[0][1][3][2] = 0 ;
		dp[0][2][1][3] = 0 ;
		dp[0][2][3][1] = 0 ;
		dp[0][3][1][2] = 0 ; 
		dp[0][3][2][1] = 0 ; 

		rep(i,1,m) {
			rep(t2,1,n) rep(t3,1,n) if(t2!=t3) {
				rep(t1,1,n) {
					if(a[i] == t2 || a[i] == t3) continue ; 
					if(t1==t2 || t1==t3) continue ;
					minimize(dp[i][a[i]][t2][t3] , dp[i-1][t1][t2][t3] + cost[t1][a[i]] ) ; 
				}
			}
			rep(t1,1,n) rep(t3,1,n) if(t1!=t3) {
				rep(t2,1,n) {
					if(a[i] == t1 || a[i] == t3) continue ; 
					if(t3==t2 || t2==t1) continue ; 
					minimize(dp[i][t1][a[i]][t3] , dp[i-1][t1][t2][t3] + cost[t2][a[i]] ) ; 
				}
			}
			rep(t1,1,n) rep(t2,1,n) if(t1!=t2) {
				rep(t3,1,n) {
					if(a[i] == t1 || a[i] == t2) continue ; 
					if(t3==t2 || t3==t1) continue ; 
					minimize(dp[i][t1][t2][a[i]] , dp[i-1][t1][t2][t3] + cost[t3][a[i]] ) ;
				}
			}
		}

		int ans = oo ; 

		rep(t1,1,n) rep(t2,1,n) rep(t3,1,n) {
			minimize(ans,dp[m][t1][t2][t3]) ; 
		}

		cout << ans ;
	}

}

namespace sub2 {	

	int dp[3][205][205] ; 

	void solve(void) {
		
		FOR(i,0,1) FOR(t1,1,n) FOR(t2,1,n) dp[i][t1][t2] = oo ; 

		dp[0][2][3] = dp[0][3][2] = 0 ; 

		int c = 1 ; 
		a[0] = 1 ; 
		int ans = oo ; 

		FOR(i,1,m) {
			int prev = (i-1)&1 ; 
			int cur = i & 1 ; 
			c = a[i-1] ; 

			FOR(t1,1,n) FOR(t2,1,n) dp[cur][t1][t2] = oo ;

			FOR(t1,1,n) if(t1!=c) FOR(t2,1,n) {
				if(t1 == t2 || t1 == c || t2 == c) continue ; 
				minimize(dp[cur][t1][t2] , dp[prev][t1][t2] + cost[c][a[i]] ) ;
				minimize(dp[cur][c][t1] , dp[prev][t1][t2] + cost[t2][a[i]] ) ;
				minimize(dp[cur][t2][c] , dp[prev][t1][t2] + cost[t1][a[i]] ) ;   
			}		
		}
		
		FOR(t1,1,n) FOR(t2,1,n) {
			minimize(ans,dp[m&1][t1][t2]) ; 
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
    if(n <= 50 and m <= 50) sub1::solve() ;
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}