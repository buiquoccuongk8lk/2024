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
int a[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {

	int dp[5005][5005] ; // số thao tác ít nhất biển đổi đoạn i..j thành 1 màu	
	int b[5005] ;

	int calc(int l,int r) {
		if(l>=r) return 0 ;
		if(dp[l][r]!=oo) return dp[l][r] ; 
		int &val = dp[l][r] ; 
		val = oo ; 
		minimize(val , calc(l+1,r) + 1) ; 
		minimize(val , calc(l,r-1) + 1) ; 
		if(b[l]==b[r]) minimize(val , calc(l+1,r-1) + 1 ) ; 
		return val ;
	}

	void solve(void) {	
		int sz = 0 ;
		FOR(i,1,n) {
			if(a[i]!=a[i-1]) {
				b[++sz] = a[i] ; 
			}
		}
		n = sz ;
		FOR(i,1,n) FOR(j,1,n) dp[i][j] = oo ;
		FOR(i,1,n) dp[i][i] = 0 ;
		cout << calc(1,n) ;
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
    sub1::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}