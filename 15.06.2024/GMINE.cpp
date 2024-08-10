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

const int N = 3e3 + 5 ;
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

int n , T ; 
ii a[N] ; 
ll dp[N][N] ; 

void init(void) {
	cin >> n >> T ; 
	FOR(i,1,n) {
		cin >> a[i].fi >> a[i].se ; 
	}
}

void process(void) {
	sort(a+1,a+1+n,[](ii u ,ii v) {
		return u.se < v.se ; 
	}) ;
	FOR(i,1,n) FOR(j,0,T-1) dp[i][j] = -inf ; 
	dp[0][0] = 0 ;
	dp[1][0] = 0 ;
	FOR(i,1,n) {
		FOR(j,0,T-1) {
			dp[i][j] = dp[i-1][j] ; 
			if(j >= a[i].fi) {
				maximize(dp[i][j],dp[i-1][j-a[i].fi] + a[i].se) ; 
			}
		}
	}
	ll ans = -inf ; 
	FOR(i,1,n) FOR(j,0,T-1) maximize(ans,dp[i][j]) ;
	FOR(i,1,n) maximize(ans,dp[i-1][T-1] + a[i].se) ;
    cout << ans ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}