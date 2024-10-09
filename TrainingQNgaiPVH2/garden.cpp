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

const int N = 2207 +3 ;
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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count()) ;
int Rand(int l,int r) {
	return l + rd()%(r-l+1) ;
}

int n , m , K ;
int a[N][N] ;

void init(void) {
	cin >> n >> m >> K ;
	FOR(i,1,n) FOR(j,1,m) cin >> a[i][j] ;
}

namespace sub1 {

	const int dx[] = { -1 , 0 , 1 } ;
	const int dy[] = { 1  , 1 , 1 } ;

	ll dp[N][N] ; 

	void solve(void) {

		FOR(i,0,n) FOR(j,0,m) dp[i][j] = -inf ;

		FOR(i,1,n) dp[i][1] = a[i][1] ; 

		int lim = n + m ; 
		FOR(sum,0,lim) {
			FOR(y,0,min(m,sum)) {
				int x = sum - y ; 
				if(x < 1 || y < 1) continue ; 				
				FOR(s,0,2)  {
					int u = dx[s] + x ; 
					int v = dy[s] + y ; 
					if(u < 1 || u > n || v < 1 || v > m) continue ;
					maximize(dp[u][v],dp[x][y] + a[u][v]) ; 
				}
			}
		}
		ll ans = -inf ; 
		FOR(i,1,n) maximize(ans,dp[i][m]) ; 
		cout << ans ;
	}	

}

namespace sub2 {

	ll dp[230][230][11] ;

	const int dx[] = { -1 , 0 , 1 } ;
	const int dy[] = { 1  , 1 , 1 } ;

	void solve(void) {
		FOR(i,0,n) FOR(j,0,m) FOR(k,0,K) dp[i][j][k] = -inf ;

		FOR(i,1,n) dp[i][1][0] = a[i][1] ; 

		int lim = n + m ; 

		FOR(k,0,K) {
			FOR(sum,0,lim) {
				FOR(y,0,min(sum,m)) {
					int x = sum - y ;
					if(x < 1 || y < 1) continue ;
					FOR(s,0,2) {
						int u = dx[s] + x ; 
						int v = dy[s] + y ;
						if(u < 1 || u > n || v < 1 || v > m) continue ;
						maximize(dp[u][v][k],dp[x][y][k] + a[u][v]) ; 
					}
					FOR(col,1,m) if(k + 1 <= K) {
						maximize(dp[x][col][k+1] , dp[x][y][k] + a[x][col]) ; 
					}
					FOR(row,1,n) if(k + 1 <= K) {
						maximize(dp[row][y][k+1] , dp[x][y][k] + a[row][y]) ; 
					}
				}
			}
		}

		ll ans = 0 ; 

		FOR(k,0,K) FOR(i,1,n) maximize(ans,dp[i][m][k]) ; 

		cout << ans ;
	}

}

namespace sub3 {

	ll dp[N][N][11] ; 
	
	struct DL { 
		ll best ; 
		int id_best ;
		ll second_best ;
		int id_second_best ;
	} ;
	DL maxi_col[N][11] , maxi_row[N][11] ;

	void update(DL maxi[N][11],int i,int k,ll val,int new_id) {
		if(maxi[i][k].best <= val) {
			maxi[i][k].second_best = maxi[i][k].best ; 
			maxi[i][k].id_second_best = maxi[i][k].id_best ; 
			maxi[i][k].best = val ; 
			maxi[i][k].id_best = new_id ;
		}else if(maxi[i][k].second_best <= val) {
			maxi[i][k].second_best = val ; 
			maxi[i][k].second_best = new_id ;
		}
	}

	void solve(void) {
		FOR(i,0,n) FOR(j,0,m) FOR(k,0,K) dp[i][j][k] = -inf ;


		FOR(i,1,n) dp[i][1][0] = a[i][1] ;

		FOR(k,0,K) {
			FOR(j,1,m) FOR(i,1,n) {
				if(i - 1 >= 1 and j - 1 >= 1) {
					maximize(dp[i][j][k] , dp[i-1][j-1][k] + a[i][j]) ; 
				}
				if(j - 1 >= 1) {
					maximize(dp[i][j][k] , dp[i][j-1][k] + a[i][j]) ; 
				}
				if(i + 1 <= n and j - 1 >= 1) {
					maximize(dp[i][j][k] , dp[i+1][j-1][k] + a[i][j]) ;
				}
				if(k >= 1) {
					if(maxi_row[i][k-1].id_best==j)  {
						maximize(dp[i][j][k] , maxi_row[i][k-1].second_best + a[i][j]) ; 
					}else {
						maximize(dp[i][j][k] , maxi_row[i][k-1].best + a[i][j]) ;
					}
					if(maxi_col[j][k-1].id_best==i) {
						maximize(dp[i][j][k] , maxi_col[j][k-1].second_best + a[i][j]) ;
					}else {
						maximize(dp[i][j][k] , maxi_col[j][k-1].best + a[i][j]) ;
					}
				}
				update(maxi_row,i,k,dp[i][j][k],j) ;
				update(maxi_col,j,k,dp[i][j][k],i) ;
			}			
		}
		ll ans = -inf ; 
		FOR(k,0,K) FOR(i,1,n) maximize(ans,dp[i][m][k]) ;
		cout << ans ;
	}

}

signed main(void) {
    #define TASK "garden"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
  	/*if(K==0) sub1::solve() ;    
   	else if(n <= 227 and m <= 227) sub2::solve() ;
   	else*/ sub3::solve() ; 
   	cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}