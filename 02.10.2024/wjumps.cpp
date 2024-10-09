/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define endl '\n'
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ; } return false ; }
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ; } return false ; }

const int N = 1e6 + 5 ; 

int n , m ;
int a[N] , b[N] , dp[N] ;  

void init() {	
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	cin >> m ; 
	FOR(i,1,m) cin >> b[i] ; 
}

void solve() {
	FOR(i,1,m) {	
		FOR(j,1,n) dp[j] = 2e9 ; 

		deque<int> dq ;
		dp[1] = 0 ; 
		int k = b[i] ;
		dq.pb(1) ; 
		
		FOR(j,2,n) {
			while(!dq.empty() && dq.front() < j - k) dq.pop_front() ; 
			int u = dq.front() ; 
			dp[j] = dp[u] + (a[u] <= a[j]) ; 
			while(!dq.empty() && ( (dp[dq.back()] > dp[j]) || (dp[dq.back()] == dp[j] && a[dq.back()] <= a[j]) ) ) dq.pop_back() ; 
			dq.push_back(j) ; 
		}
		
		cout << dp[n] << ' ' ; 
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 