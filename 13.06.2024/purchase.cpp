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

int n , K ; 
int a[N] ; 
long long dp[2][2][100002] ; 

void init(void) {
	cin >> n >> K ;
	FOR(i,1,n) cin >> a[i] ; 
}

void process1(void) {
	FOR(i,0,1) FOR(j,0,1) FOR(k,0,K) dp[i][j][k] = -inf ;
	ll ans = 0 ; 
	dp[0][0][0] = 0 ;
	dp[1][0][0] = -a[1] ; 
	dp[1][1][0] = 0 ;
	FOR(i,2,n) {
		int prev = (i-1)&1 ; 
		int cur = i&1 ;
		FOR(k,0,K) dp[cur][0][k] = dp[cur][1][k] = -inf ; 
		FOR(k,0,K) {
			dp[cur][0][k] = dp[prev][0][k] ; 
			dp[cur][1][k] = dp[prev][1][k] ; 
			maximize(dp[cur][0][k],dp[prev][1][k] - a[i]) ; 
			if(k>=1) {
				maximize(dp[cur][1][k],dp[prev][0][k-1] + a[i]) ; 
			}
			maximize(ans,dp[cur][0][k]) ; 
			maximize(ans,dp[cur][1][k]) ; 
		}
		FOR(j,0,1) {
			FOR(k,0,K) {
				dp[prev][j][k] = dp[cur][j][k] ; 
			}
		}
	}	
	cout << ans ;
}

void process2(void) {


}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    if(n*K<=3e7) process1() ;
    else process2() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}