/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n' 
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)

template <class X,class Y> bool maximize(X &x , const Y &y) {
	if(x < y) {
		x = y ; 
		return 1 ; 
	} else return 0  ;
}

template <class X,class Y> bool minimize(X &x , const Y &y) {
	if(x > y) {
		x = y ; 
		return 1 ; 
	} else return 0 ; 
}

const int N = 5e6 + 5 ;
const ll inf = 1e18 ; 

int n , delta , p , q , m ; 

void init(void) {
	cin >> n >> delta ; 
	cin >> p >> q  >> m ; 	
}

namespace sub {

	ll a[2*N] ;
	ll b[2*N] ; 
	ll res[2*N] ; 

	void solve(void) {
		
		ll ans = inf ; 

		FOR(i,1,n) { 
			a[i] = (p * i)%m + q;  
		}		

		FOR(i,1,n) a[i+n] = a[i] ; 

		FOR(i,1,2*n) {
			b[i] = a[i] + i * delta ; 
		}

		deque<ll> dq ; 

		FOR(i,1,2*n) {
			while(!dq.empty() and dq.front() < i - n + 1 ) dq.pop_front() ; 
			while(!dq.empty() and b[dq.back()] <= b[i]) dq.pop_back() ;
			dq.push_back(i) ; 
			if(!dq.empty()) res[i] = b[dq.front()] ; 
		}	

		FOR(i,n,2*n) {
			minimize(ans, res[i] - (i - n) * delta) ;
		}

		cout << ans ; 
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
    sub::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}