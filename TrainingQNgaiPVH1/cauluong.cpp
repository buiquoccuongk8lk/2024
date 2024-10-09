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

int n , m , L , R ; 
int a[N] ;

void init(void) {
	cin >> n >> m ;
	cin >> L >> R ;
	FOR(i,1,m) cin >> a[i] ;
}

namespace sub_task1 {

	void solve(void) {
		sort(a+1,a+1+m) ;
		int ans = 0 ; 
		if(L < a[1]) {
			maximize(ans , abs(L - a[1]) ) ; 
		}
		if(R > a[m]) {
			maximize(ans , abs(R - a[m]) ) ; 
		}
		FOR(i,1,m-1) {
			int u = a[i] ; int v = a[i+1] ; 
			int mid = (u + v) >> 1 ; 
			FOR(range,-500,500) {
				int new_mid = mid + range ; 
				if(new_mid>=L and new_mid<=R and new_mid>u and new_mid<v) {
					maximize(ans ,  min ( abs(new_mid - u) , abs(new_mid - v) ) ) ;
				}
			}
		}
		cout << ans << ' ' ;
	}

}

signed main(void) {
    #define TASK "cauluong"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int sub_task , test ; 
    cin >> sub_task >> test ;
    while(test--) {
    	init() ; 
    	sub_task1::solve() ;
    }
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}