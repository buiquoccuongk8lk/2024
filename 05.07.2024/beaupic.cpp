#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 5e5 + 5 ;
int n ,K ;
int a[maxn] ;

namespace sub1 {

	const int LO = __lg(maxn) + 1 ; 
	int rmq_max[maxn][LO] ;
	int L[maxn] , R[maxn] ; 

	int get_max(int l,int r) {
		int k = __lg(r-l+1) ; 
		return max(rmq_max[l][k],rmq_max[r-(1<<k)+1][k]) ; 
	}

	void solve(void) {

		FOR(i,1,n) rmq_max[i][0] = a[i] ; 

		for(int j(1) ; (1<<j) - 1 <= n ; j++) FOR(i,1,n-(1<<j)+1) {
			rmq_max[i][j] = max(rmq_max[i][j-1],rmq_max[i+(1<<(j-1))][j-1]) ; 
		}

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

		ll ans = 0 ; 

		FOR(i,1,n) {
			int l = L[i] ; 
			int r = i ; 
			int posL = i ; 
			while(l <= r) {
				int mid = (l+r)>>1 ; 
				if( abs(a[i] - get_max(mid,i)) <= K ) posL = mid , r = mid - 1 ; 
				else l = mid + 1 ; 
			}

			l = i ; 
			r = R[i] ; 
			int posR = i ;
			while(l <= r) {
				int mid = (l+r)>>1 ; 
				if( abs(a[i] - get_max(i,mid)) <= K ) posR = mid , l = mid + 1 ; 
				else r = mid - 1 ; 
			}
			ans+= (i - posL + 1) * (posR - i + 1) ; 
			//cout << posL << ' ' << i << ' ' << posR << endl ; 
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
    cin >> n >> K ; 
    FOR(i,1,n) cin >> a[i] ; 
    sub1::solve() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}