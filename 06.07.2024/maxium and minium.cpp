#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 5e5 + 5 ;
const int LO = __lg(maxn) + 1 ;

int n ;
int a[maxn] , L[maxn] ;
vector<int> vec_val[(int)1e6 + 5] ;
int rmq[maxn][LO] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> a[i] ; 
}

int get(int l,int r) {
	int k = __lg(r-l+1) ; 
	return max(rmq[l][k],rmq[r-(1<<k)+1][k]) ; 
}

void solve(void) {
	deque<int> dq ; 
	FOR(i,1,n) {
		while(!dq.empty() and a[dq.front()] >= a[i]) dq.pop_front() ; 
		L[i] = (dq.empty() ? 1 : dq.front() + 1) ; 
		dq.push_front(i) ; 
	}
	FOR(i,1,n) vec_val[a[i]].pb(i) ;
	FOR(i,1,n) rmq[i][0] = a[i] ; 
	for(int j(1) ; (1<<j) - 1 <= n ; j++) {
		for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
			rmq[i][j] = max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
		}
	}
	ll ans = 0 ;
	int lim_val = *max_element(a+1,a+1+n) ;
	FOR(i,1,n) {
		int lim_left = L[i] ; 
		for(int val = a[i] ; val <= lim_val ; val++) {
			for(int j = vec_val[val].size() - 1 ; j >= 0 ; j--) {
				int l = vec_val[val][j] ; 
				if(l < lim_left) break ; 
				if( get(l,i)==val ) ans++ ;
			}
		}
	}
	cout << ans << '\n' ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int T ; cin >> T ;
    while(T--) {
    	init() ;
    	solve() ; 
    }
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}