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

const int N = 50 + 5 ;
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
int Hanh[N] , cute[N] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> Hanh[i] ;
	FOR(i,1,n) cin >> cute[i] ;
}

namespace sub1 {

	vi ans ;

	void solve(void) {

		long double maxi = 0 ;
		FOR(mask,0,(1<<n)-1) { 
			vi ones ; 
			FOR(j,0,n-1) if( (mask >> j) & 1) ones.pb(j) ;
			if(ones.empty()) continue ;
			long double tu = 0 ;
			long double mau = 0 ;
			for(auto x : ones) tu+= cute[x+1] ; 
			for(auto x : ones) mau+= Hanh[x+1] ; 
			if( maximize(maxi , (long double) tu / mau) ) {
				ans.clear() ;
				for(auto x : ones) ans.pb(x+1) ; 
			}
		}
		cout << ans.size() << endl ;
		for(auto x : ans) cout << x << ' ' ;

	}

}

namespace sub2 {

	struct DP {
		ll tu ; 
		ll mau ;
		long double val ;  
	}dp[N] ; 
	vi res ;
	void trace(int i) {
		if(i==0) return ; 
		FOR(j,1,i-1) {
			double sum = (double) (dp[j].tu + cute[i]) / (dp[j].mau + Hanh[i]) ;
			if(sum == dp[i].val) {
				trace(j) ;
			}
		}
		res.pb(i) ;
	}

	void solve(void) {
		set<pair<double,int>> se ; 
		FOR(i,1,n) {
			se.insert({ (double) cute[i] / Hanh[i] , i }) ; 
		}
		cout << 1 << endl ; 
		auto it = *se.rbegin() ; 
		cout << (it.se) ;
	}

}

signed main(void) {
    #define TASK "survey"	
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    if(n <= 20) sub1::solve() ;
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}