#include <bits/stdc++.h>
using namespace std ;
#define sz(a) (int)a.size() 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;
const int oo = 2e9 ; 

int n ; 
int hung[maxn] , cute[maxn] ;

namespace sub1 {

	void solve(void) {
		int ans = 0 ; 
		FOR(mask,0,(1<<n)-1) {
			vector<int>ones ; 
			int money = 0 ; 
			//vector<int>bits_on ;
			FOR(i,0,(n-1)) {
				if((mask>>i)&1) {
					ones.pb(cute[i+1]) ; 
			//		bits_on.pb(i+1) ; 
				} else {
					money+=hung[i+1] ; 
				}
			}
			sort(all(ones)) ; 
			int cnt = 0 ; 
			for(auto x : ones) if(money >= x) {
				money-=x ;
				cnt++ ;
			}
			if(cnt >= n - __builtin_popcountll(mask)) {
				/*cout << n - __builtin_popcountll(mask) << ':' ;
				for(auto x : bits_on) cout << x << ' ' ;
				cout << endl ;*/
				ans = max(ans , n - __builtin_popcountll(mask) ) ; 
			}
		}
		cout << ans ; 
	}
}

namespace sub2 {

	struct BG {
		int stole ;  
		int help ;  
		bool operator <(const BG &x) const {
			return stole + help > x.stole + x.help ; 
		}
	} poli[maxn] ; 	
	ll pre[maxn] , suf[maxn] ;

	bool check(int mid) {	

		priority_queue<int,vector<int>,greater<int>>pq_min ; 
		priority_queue<int,vector<int>>pq_max ; 

		FOR(i,1,n-mid) {
			pq_min.push(poli[i].stole) ; 
			pre[i] = pre[i-1] + poli[i].stole ; 
			if(sz(pq_min) > mid) {
				pre[i] -= pq_min.top() ; pq_min.pop() ; 
			}
		}

		FORD(i,n,mid) {
			pq_max.push(poli[i].help) ; 
			suf[i] = suf[i+1] + poli[i].help ;
			if(sz(pq_max) > mid) {
				suf[i]-= pq_max.top() ; pq_max.pop() ; 
			}
		}

		FOR(i,mid,n-mid) return (pre[i] >= suf[i+1]) ; 

		return false ;  
	}

	void solve(void) {

		FOR(i,1,n) {
			poli[i] = {hung[i],cute[i]} ; 
		}

		sort(poli+1,poli+1+n) ;

		int l = 1 ; 
		int r = n ; 
		int ans = 0 ; 

		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if(check(mid)) {
				ans = mid ; 
				l = mid + 1 ; 
			} else r = mid - 1 ; 
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
    cin >> n ; 
    FOR(i,1,n) cin >> hung[i] ; 
    FOR(i,1,n) cin >> cute[i] ;
    /*if(n <= 20) sub1::solve() ;  
    else */sub2::solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}