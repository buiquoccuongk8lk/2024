/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N = 1e6 + 5 ;
const long long inf = 1e18 ;

int k ;
int n , m ; 
int a[N] , b[N] , cnt[N] ;

void init(void) {	
    cin >> k ;
    cin >> n ;
    for(int i(1) ; i <= n ; i++) cin >> a[i] ; 
    cin >> m ; 
	for(int i(1) ; i <= m ; i++) cin >> b[i] ;
}

namespace sub {

	bool Check(ll mid) {
		ll ret = 0 ; 
		
		for(int i = 1 ; i <= m ; i++) {
			if(b[i] < 0) {
				int l = 1 ; 
				int r = n ;
				int pos = -1 ; 
				while(l <= r) {
					int m = (l+r)>>1 ; 
					if(a[m] * b[i] <= mid) {
						pos = m ; 
						r = m - 1 ; 
					} else l = m + 1 ; 
				}
				if(pos!=-1) ret+= n - pos+1 ; 
			} else {
				int l = 1 ; 
				int r = n ; 
				int pos = -1 ;
				while(l <= r) {
					int m = (l+r)>>1 ; 
					if(a[m] * b[i] <= mid) {
						pos = m ;
						l = m + 1 ; 
					} else r = m - 1 ; 
				}
				if(pos!=-1) ret+= pos ; 
			}
		} 

		return ret >= k ;
	}

	void solve(void) {	

		sort(a+1,a+1+n) ; 
		sort(b+1,b+1+m) ; 
		ll ans = 0 ;
		ll l = -1e18 ; 
		ll r = 1e18 ;
	

		while(l <= r) {
			ll mid = (l+r)>>1 ; 
			if(Check(mid)) {
				ans = mid ; 
				r =  mid - 1 ;			
			} else l = mid + 1 ; 
		}

		cout << ans; 

	}	

}

namespace sub2 {

	void solve(void) {
		cout << endl ;
		vector<int> vec ; 
		for(int i(1) ; i <= n ; i++) for(int j(1) ; j <= m ; j++) vec.push_back(a[i] * b[j]) ; 
		sort(vec.begin(),vec.end()) ; 
		cout << vec[k-1] ;  
		cout << endl ;
		for(auto x : vec) cout << x << ' ' ;		
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
    //sub2::solve() ; 

    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0 ; 
}