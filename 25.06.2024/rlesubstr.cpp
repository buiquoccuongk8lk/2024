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
const long long MOD = 111539786 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

string s ; 
int n ; 

void init(void) {
	cin >> s ; 
	n = sz(s) ; 
	s = '*' + s ; 
}	

namespace sub_task {	
	tct void add(WORK &x, const HARD &y) {x+=y ; x%=MOD; }

	struct bg {
		int x ; 
		int sl ; 
	} a[N] ; 
	
	int dd[N] ;

	long long dp[N] ; // số lượng xâu con kết thúc tại kí tự a[i].x 

	void solve(void) {

		FOR(i,1,n) a[i].x = a[i].sl = 0 ;

		FOR(i,1,n) dp[i] = 0 ;

		int sz = 0 ;

		FOR(i,1,n) {
			if(s[i] >= 'a' and s[i] <= 'z') {
				sz++ ; 
				a[sz].x = s[i] - 'a' + 1 ;
				a[sz].sl = 0 ;
			} else {
				a[sz].sl = ( a[sz].sl * 10 + s[i] - 48)%MOD ;
			}
		}
	
		dp[0] = 1 ; 
		a[0].x = 0 ;
		a[0].sl = 1 ;

		FOR(i,0,sz-1) {
			FOR(j,1,26) dd[j] = 0 ; 
			FOR(j,i+1,sz) {
				if(dd[a[j].x]) continue ; 
				dd[a[j].x] = 1 ; 
				if(a[j].x!=a[i].x) add(dp[j] , dp[i] * a[i].sl%MOD ) ; 
				else add(dp[j],dp[i]) ; 
			}
		}

		ll ans = 0 ;
		FOR(i,1,sz) add(ans , dp[i] * a[i].sl%MOD ) ; 
		
		cout << ans%MOD << endl ;
	}

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int test ; cin >> test ; 
    while(test--) {
    	init() ; sub_task::solve() ;
	}
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}