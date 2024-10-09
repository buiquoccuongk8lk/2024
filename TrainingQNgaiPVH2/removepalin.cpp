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

int n ; 
string s ;

void init(void) {
	cin >> s ; n = sz(s) ; s = "*" + s ;
}

namespace sub1 {

	int dp[3][26][26] ; 

	int cost(char x,char y) {
        int d = abs(x-y) ;
        return min(d , 26 - d) ;
    }

	void solve(void) {
        FOR(j,0,25) FOR(k,0,25) if(j!=k) {
            int cur = 2 & 1 ; 
            dp[cur][j][k] = cost(s[2] , j + 'a') + cost(s[1] , k + 'a') ;
        }

        FOR(i,2,n-1) {
            int cur = i & 1 ;
            int nxt = (i+1) & 1 ;
            FOR(j,0,25) FOR(t,0,25) dp[nxt][t][j] = 2e9 ;
            FOR(j,0,25) FOR(k,0,25) if(j!=k) {
                FOR(t,0,25) if(t!=j and t!=k) {
                    minimize(dp[nxt][t][j] , dp[cur][j][k] + cost(s[i+1] , t + 'a') ) ;
                }
            }
            FOR(j,0,25) FOR(t,0,25) {
                dp[cur][j][t] = dp[nxt][j][t] ; 
            }
        }

        ll ans = inf ; 
        FOR(j,0,25) FOR(t,0,25) if(j!=t) minimize(ans,dp[n&1][j][t]) ; 

        cout << ans ;

	}

}

namespace sub2 {

    int val[N][5] ;
    int dp[3][26][26] ;

    void solve(void) {

        FOR(i,1,n) FOR(j,-2,2) {
            val[i][j+2] = (s[i] - 'a' + j + 26)%26 ;
        }

        FOR(j,0,4) FOR(k,0,4) if(val[2][j] != val[1][k]) {
            dp[2&1][j][k] = abs(j-2) + abs(k-2) ;
        }

        FOR(i,2,n-1) {
            int cur = i&1 ; 
            int nxt = (i+1)&1 ; 
            FOR(j,0,4) FOR(k,0,4) dp[nxt][j][k] = 2e9 ;
            FOR(j,0,4) FOR(k,0,4) if(val[i][j]!=val[i-1][k]) {
                FOR(t,0,4) if(val[i+1][t]!=val[i][j] and val[i+1][t]!=val[i-1][k]) {
                    minimize(dp[nxt][t][j] , dp[cur][j][k] + abs(t-2) ) ;
                }
            }
            FOR(j,0,4) FOR(k,0,4) dp[cur][j][k] = dp[nxt][j][k] ;
        }
        ll ans = inf ;
        FOR(j,0,4) FOR(k,0,4) if(val[n][j]!=val[n-1][k]) {
            minimize(ans,dp[n&1][j][k]) ; 
        }
        cout << ans ;
    }

}

signed main(void) {
    #define TASK "removepalin"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    if(n <= 1e4) sub1::solve() ;
    else sub2::solve() ;  
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}