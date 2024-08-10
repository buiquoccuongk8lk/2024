#include <bits/stdc++.h>
using namespace std ; 
#define int long long
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;
const int oo = 2e9 ;
int n ;
int a[maxn] ;
ll dp[(int)(1<<15) + 2] ; 
int b[maxn] ;

void process(void) {
		multiset<int> ms ; 
		FOR(i,1,n) ms.insert(a[i]) ; 
		int sz = 0 ; 
		FOR(i,1,n) {
			if(ms.empty()) break ;
			if(sz <= 9) {
				b[++sz] = *ms.rbegin() ; 
				ms.erase(ms.find(*ms.rbegin())) ; 
			}
		}
		FOR(i,1,n) {
			if(ms.empty()) break ;
			if(sz <= 15) {
				b[++sz] = *ms.begin() ; 
				ms.erase(ms.find(*ms.begin())) ; 
			}
		}
		FOR(i,0,(1<<sz)-1) dp[i] = -oo ; 
		dp[0] = 0 ; 
		FOR(mask,1,(1<<sz)-1) {
			if(__builtin_popcountll(mask)%3!=0) continue ; 
			vector<int> ones ; 
			FOR(j,0,sz-1) if( (mask >> j) & 1 ) ones.pb(j) ;
			for(auto x : ones) for(auto y : ones) {
				for(auto z : ones) {
					if(x!=z and x!=y and y!=z) {
						int prev_mask = mask ^ (1 << x) ; 
						prev_mask = prev_mask ^ (1 << y) ; 
						prev_mask = prev_mask ^ (1 << z) ; 
						dp[mask] = max(dp[mask] , dp[prev_mask] + b[x+1] * b[y+1] * b[z+1]) ; 
					}
				}
			}
		}
		ll ans = 0 ;
		FOR(mask,0,(1<<sz)-1) {
			if(__builtin_popcountll(mask)==9) {
				ans = max(ans , dp[mask]) ; 
			}
		}
		cout << ans ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
    process() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}