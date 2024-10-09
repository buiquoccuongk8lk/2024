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

ll a , n ;

void init(void) {
	cin >> a >> n ;
}

namespace sub1 {
	void solve(void) {
		cout << ( n == 1 ? 0 : 1 ) ;
	}
}

namespace sub2 {
	void solve(void) {
		FOR(i,0,a) {
			if( (i ^ a) %n == 0 ) {
				cout << i ;
				return ;
			}
		}
	}
}

namespace sub3 {
	void solve(void) {
		if( (a >> 0) & 1 ) {
			cout << 1 ; 
		}else cout << 0 ;
	}
}

namespace sub4 {

	void solve(void) {
		ll ans = 0 ;
		ll k = __lg(n) ; 	
		FOR(i,0,k-1) {
			if( ( a >> i) & 1ll * 1 ) ans+= (1ll*1 << i) ; 
		}
		cout << ans ;
	}

}

namespace sub5 {

	void solve(void) {
		ll ans = inf ; 
		ll d = a - a % n ;
		FOR(i,-1e2,1e2) {
			if(d + i*n >= 0) {
				minimize(ans , (d + i*n) xor a ) ; 
			}
		}
		cout << ans ;
	}
	
}

signed main(void) {
    #define TASK "XOR"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    /*if(a==1) sub1::solve() ;
    else if(n==2) sub3::solve() ;
    else if(__builtin_popcountll(n)==1) sub4::solve() ; 
    else if( a <= 1e5 ) sub2::solve() ;
    else*/ sub5::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}