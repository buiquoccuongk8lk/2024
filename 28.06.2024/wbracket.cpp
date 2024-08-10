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
ll k ;

void init(void) {
	cin >> n >> k ; 
}

namespace sub1 {
	int cnt = 0 ; 
	char a[N] ;
	void backtrack(int pos) {
		if(pos > n) {
			int sum = 0 ; 
			bool ok = false ;
			FOR(i,1,n) {
				sum+=  ( a[i] == '(' ? 1 : -1 ) ; 
				if(sum < 0) {
					ok = true ; 
				}
			}
			if(sum != 0 || ok ) { 
				cnt++ ; 
				if(cnt==k) {
					FOR(i,1,n) cout << a[i] ;
					return ; 
				}
			}
		} else {
			FOR(j,0,1) {
				a[pos] = (  j == 0 ? '(' : ')'  ) ; 
				backtrack(pos+1) ;
			}
		}
	}
	void solve(void) {
		backtrack(1) ;
	}

}

namespace sub2 {

	ll dp[124][124][3] ; // di tu 1...i - 1 co c ki tu '(' 
	bool dd[124][124][3] ;
	char x[N] ; 

	ll calc(int i,int cnt,int ok) {
		if(i>n) return (ok || cnt!=n/2) ; 
		if(dd[i][cnt][ok]!=0) return dp[i][cnt][ok] ;
		dd[i][cnt][ok] = 1 ;
		ll &val = dp[i][cnt][ok] ; 
		val = 0 ; 
		val = calc(i+1,cnt+1,ok) + calc(i+1,cnt,ok || (cnt < i - cnt) ) ;  
		return val ;
	}

	void find(int i,int cnt,int ok) {
		if(i>n) return ;
		if(calc(i+1,cnt+1,ok) < k) {
			k = k - calc(i+1,cnt+1,ok) ; 
			x[i] = ')' ;
			find(i+1,cnt, (ok || cnt < i - cnt) ) ; 
		} else {
			x[i] = '(' ; 
			find(i+1,cnt+1,ok) ; 
		}
	}

	void solve(void) { 
		find(1,0,0) ; 
		FOR(i,1,n) cout << x[i] ; 
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
    /*if(n <= 20) sub1::solve() ;
    else*/ 
 /*   sub1::solve() ;
    cout << endl ;*/
    sub2::solve() ;  
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}