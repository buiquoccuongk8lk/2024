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
	cin >> n ;
	cin >> s ; 
	s = "*" + s ;
}

namespace sub1 {


	void solve(void) {
		int ans = 0 ; 

		if(s[1] == 'F') {
			int j = 1 ; 
			while(j <= n and s[j] == 'F') j++ ; 
			FORD(i,j,2) {
				swap(s[i],s[i-1]) ; 
				ans++ ;
			}
		}

		FOR(i,1,n) {
			if(i%2==0) {
				if(s[i]=='T') continue ; 
				int pos = i ; 
				while(pos <= n and s[pos] == 'F') {
					pos++ ; 
				}
				FORD(j,pos,i+2) {
					swap(s[j],s[j-1]) ;
					ans++ ; 
				}
			}else {
				if(s[i]=='F') continue ; 
				int pos = i ;
				while(pos <= n and s[pos] == 'T') {
					pos++ ;
				}
				FORD(j,pos,i+2) {
					swap(s[j],s[j-1]) ; 
					ans++ ; 
				}
			}
		}
 		cout << ans ;

	}

}

namespace sub2 {

	void solve(void) {
		int ans = 0 ; 
		deque<int> dq ; 
		FOR(i,1,n) if(s[i]=='T') {
			dq.pb(i) ; 
		}
		for(int j(n - 1) ; j ; j-=2) {
			if(dq.empty()) break ; 
			ans+= abs ( dq.back() - j ) ; 
			dq.pop_back() ; 
		}
		cout << ans ;
	}

}

signed main(void) {
    #define TASK "thesis"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    if(n <= 1e3) sub1::solve() ;
    else sub2::solve() ;  
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}