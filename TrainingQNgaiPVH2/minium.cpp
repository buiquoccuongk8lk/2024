/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define cout cerr

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

const int N = 5e6 + 5 ;
const int LO = 19 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , numMin , numMax ; 
int a[N] ; 

void init(void) {
	cin >> n >> numMin >> numMax ; 
	FOR(i,1,n) cin  >> a[i] ; 
}

namespace sub1 {
	int L[N] , R[N] ;
	ll pre[N] ;

	void solve(void) {
		deque<int> dq ; 
		FOR(i,1,n) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			L[i] = (dq.empty() ? 1 : dq.front() + 1) ; 
			dq.push_front(i) ; 
		}
		while(!dq.empty()) dq.pop_front() ;
		FORD(i,n,1) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			R[i] = (dq.empty() ? n : dq.front() - 1) ; 
			dq.push_front(i) ;
		}	
		ll ans = -inf ; 
		FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 
		int posL = -1 , posR = -1 ;
		FOR(i,1,n) {
			if(a[i] >= numMin and a[i] <= numMax) {
				FOR(u,L[i],i) {
					FOR(v,i,R[i]) {
						if( maximize(ans,pre[v] - pre[u-1]) ) {
							posL = u ;
							posR = v ;
						}
					}
				}
			}
		}
		cout << ans << endl ;
		cout << posL << ' ' << posR ;
	}

}

namespace sub2 {
	int L[(int)3e5+5],R[(int)3e5+5] ;
	ll pre[(int)3e5+5] ; 
	ll rmq_max[(int)3e5+5][LO] ;
	ll rmq_min[(int)3e5+5][LO] ; 

	void solve(void) {
		deque<int> dq ; 
		FOR(i,1,n) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			L[i] = (dq.empty() ? 1 : dq.front() + 1) ; 
			dq.push_front(i) ; 
		}
		while(!dq.empty()) dq.pop_front() ;
		FORD(i,n,1) {
			while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
			R[i] = (dq.empty() ? n : dq.front() - 1) ; 
			dq.push_front(i) ;
		}	
		ll ans = -inf ; 
		FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;
		FOR(i,1,n) {
			rmq_max[i][0] = rmq_min[i][0] = pre[i] ;
		} 	
		for(int j(1) ; (1<<j) <= n ; j++) {
			for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
				rmq_max[i][j] = max(rmq_max[i][j-1] , rmq_max[i+(1<<(j-1))][j-1]) ; 
				rmq_min[i][j] = min(rmq_min[i][j-1] , rmq_min[i+(1<<(j-1))][j-1]) ; 
			}
		}

	}

}

signed main(void) {
    #define TASK "mimimum"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    sub1::solve() ; 
    sub2::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}