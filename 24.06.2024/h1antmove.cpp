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

int n , L , m ; 
int t[N] ; 
struct ants {
	int x , w , d , t ; 
	void input(int i) {
		cin >> x >> w >> d ; 
	} 
} a[N] ; 

void init(void) {
	cin >> n >> L >> m ; 
	FOR(i,1,n) a[i].input(i) ; 
	FOR(i,1,m) cin >> t[i] ;
}

namespace sub_task {

	ii p[N] ;
	ll pre[N] ;
	ll time[N] ;

	void solve(void) {

		FOR(i,1,n) {
			if(a[i].d) a[i].t = abs(L - a[i].x) ; 
			else a[i].t = a[i].x ; 
		}

		sort(a+1,a+1+n,[](ants u,ants v) {
			return u.x < v.x ;
		}) ; 

		deque<int> dq ; 

		FOR(i,1,n) dq.pb(a[i].w) ;

		sort(a+1,a+1+n,[](ants u,ants v) {
			return u.t < v.t ; 
		}) ;

		FOR(i,1,n) {
			if(!a[i].d) {
				p[i] = {a[i].t , dq.front()} ; 
				dq.pop_front() ; 
			}else {
				p[i] = {a[i].t , dq.back()} ; 
				dq.pop_back() ;
			}
		}

		FOR(i,1,n) pre[i] = pre[i-1] + p[i].se ; 
		
		FOR(i,1,n) time[i] = p[i].fi ; 

		FOR(i,1,m) { 
			int pos = upper_bound(time+1,time+1+n,t[i]) - time ; 
			pos--; 
			cout << pre[pos] << ' ' ;
		}

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
    sub_task::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}