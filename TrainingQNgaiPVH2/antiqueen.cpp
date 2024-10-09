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
const long long MOD = 998244353 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
tct void add(WORK &x , const HARD &y) { x+=y ; if(x>=MOD)x-=MOD ; }
tct void sub(WORK &x , const HARD &y) { x-=y ; x+=MOD*MOD ; x%=MOD ; }

int r , c , K ; 

void init(void) {
	cin >> r >> c >> K ;
}

namespace sub1 {

	int dp[37][37][37] ;

	bool check(int x,int y,int u,int v) {
		if(x==u || y==v) return 0 ;
		if(u + v == x + y) return 0 ;
		if(u - v == x - y) return 0 ; 
		return 1 ;
	}
 
	void solve(void) {
 
		FOR(i,1,r) FOR(j,1,c) dp[i][j][0] = 1 ; 
 
		FOR(k,0,K-1) {
			FOR(i,1,r) FOR(j,1,c) {
				FOR(x,1,r) FOR(y,1,c) {
					if(check(i,j,x,y)) {
						add(dp[x][y][k+1] , dp[i][j][k]) ;
					}
				}
			}
		}
		ll ans = 0 ; 
		FOR(i,1,r) FOR(j,1,c) add(ans,dp[i][j][K]) ; 
		cout << ans ;
	}

}


namespace sub2 {

	ll dp[230][230][2] ;
	ll sumAll[2] , sumAdd[(int)227*2+2][2] , sumSub[(int)230*2+2][2] , sumCol[230][2] , sumRow[230][2] ;

	void solve(void) {
		
		FOR(i,1,r) {
			FOR(j,1,c) {
				dp[i][j][0&1] = 1 ; 
				sumAll[0&1]+=dp[i][j][0&1] ; 
				sumAdd[abs(i+j)][0&1]+=dp[i][j][0&1] ; 
				sumSub[i-j+227][0&1]+=dp[i][j][0&1] ;
				sumRow[i][0&1]+=dp[i][j][0&1] ; 
				sumCol[j][0&1]+=dp[i][j][0&1] ;
			}
		}

		FOR(k,1,K) {
			int cur = k&1 ; 
			int prev = (k-1)&1 ; 

			FOR(i,1,r) FOR(j,1,c) {
				dp[i][j][cur] = 0 ;
				sumAll[cur] = 0 ;
				sumAdd[abs(i+j)][cur] = 0 ;
				sumSub[i-j+227][cur] = 0 ; 
				sumRow[i][cur] = 0 ;
				sumCol[j][cur] = 0 ;
				add(dp[i][j][cur],sumAll[prev]) ; 
				sub(dp[i][j][cur],sumAdd[abs(i+j)][prev]) ; 
				sub(dp[i][j][cur],sumSub[i-j+227][prev]) ; 
				sub(dp[i][j][cur],sumCol[j][prev]) ; 
				sub(dp[i][j][cur],sumRow[i][prev]) ; 
				add(dp[i][j][cur],dp[i][j][prev]) ; 
				add(dp[i][j][cur],dp[i][j][prev]) ; 
				add(dp[i][j][cur],dp[i][j][prev]) ; 
			}

			FOR(i,1,r) FOR(j,1,c) {
				add(sumAll[cur],dp[i][j][cur]) ; 
				add(sumAdd[abs(i+j)][cur],dp[i][j][cur]) ; 
				add(sumSub[i-j+227][cur],dp[i][j][cur]) ;
				add(sumRow[i][cur],dp[i][j][cur]) ;
				add(sumCol[j][cur],dp[i][j][cur]) ;
			}

		}

		ll ans = 0 ; 
		FOR(i,1,r) FOR(j,1,c) add(ans,dp[i][j][K&1]) ; 

		cout << ans ; 
	}	

}

signed main(void) {
    #define TASK "antiqueen"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    if( r <= 37 and c <= 37 and K <= 37) sub1::solve() ;
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}