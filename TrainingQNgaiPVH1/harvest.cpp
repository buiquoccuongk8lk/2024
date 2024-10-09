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

int numRobot , numFlow ;
ll Flow[N] , rob[N] ; 

void init(void) {

}

namespace sub {

	bool Check(ll mid) {
		int l = 1 ;
		FOR(i,1,numRobot) {
			int r = l ; 
			while(r <= numFlow) {
				ll cost = 0 ;
				if(rob[i] < Flow[l]) {
					cost+= Flow[r] - rob[i] ; 
				}else if(rob[i] >= Flow[r]) {
					cost+= rob[i] - Flow[r] ; 
				}else {
					cost += min( rob[i] + Flow[r] - 2*Flow[l] , Flow[r] - rob[i] + Flow[r] - Flow[l]) ; 
				}
				if(cost <= mid) r++ ; 
				else break ; 
			}
			l = r ; 
		}
		return (l > numFlow) ; 
	}

	void solve(void) {	
		FOR(i,1,numRobot) cin >> rob[i] ;
		FOR(i,1,numFlow) cin >> Flow[i] ;
		sort(rob+1,rob+1+numRobot) ; 
		sort(Flow+1,Flow+1+numFlow) ;
		ll l = 0 ;
		ll r = 1e13 ; 
		ll ans = -1 ; 
		while(l <= r) {
			ll mid = (l+r)>>1 ;
			if(Check(mid)) {
				ans = mid ; 
				r = mid - 1 ; 
			}else l = mid + 1 ; 
		}
		cout << ans << ' ' ;
	}

}

signed main(void) {
    #define TASK "harvest"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    while( cin >> numRobot >> numFlow ) {
    	if(numRobot==0 and numFlow==0) return 0 ;
    	sub::solve() ;
    }
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}