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

int n , k ;
struct DL{
	int p ; 
	int t ; 
	int id ;
}a[N] ; 

void init(void) {
	cin >> n >> k ; 
	FOR(i,1,n) {
		cin >> a[i].p >> a[i].t ;
		a[i].id = i ;
	}
}

namespace sub {

	void solve(void) {

		long double ans = 0 ;

		FOR(i,1,n) ans+= a[i].p ; 

		sort(a+1,a+1+n,[](DL u,DL v) {
			if(u.t==v.t) return u.p > v.p ;
			else return u.t < v.t ;
		}) ; 
		//cout<< ans << endl ;
		int t1 = 0 ;
		FOR(i,1,n) t1+=(a[i].t==1) ; 
		if(t1 < k-1) {
			FOR(i,1,n) {
				if(a[i].t==1) ans-= (long double) a[i].p / 2 ; 
			}
		}else {		
			FOR(i,1,k-1) ans-= (long double)(a[i].p)/2 ; 
			if(t1 >= k) ans-=min((long double)a[t1].p,(long double)a[n].p)/2 ;
		}
		/*FOR(i,1,n) {
			cout << a[i].p << ' ' << a[i].t << ' ' << a[i].id << endl ;
		}*/
		cout << fixed << setprecision(1) << ans << endl ;
		cout << n - k + 1 << ' ' ; 
		FOR(i,k,n) cout << a[i].id << ' ' ;
		cout << endl ;
		FOR(i,1,k-1) {
			cout << 1 << ' ' << a[i].id << endl ; 
		}	
	}

}

signed main(void) {
    #define TASK "discounts"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int sub_task ; cin >> sub_task ;
    init() ; 
    sub::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}