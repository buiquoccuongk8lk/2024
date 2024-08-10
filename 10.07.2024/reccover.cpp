#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 
#define ii pair<int,int>
#define fi first
#define se second
#define int long long

const int maxn = 5e3 + 5 ;
const int oo = 2e9 ; 
const ll inf = 1e18 ; 

int n ;
ii a[maxn] , b[maxn] ; 
ll dp[maxn] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ; 
}

void solve(void) {	

	FOR(i,1,n) {
		a[i].fi=abs(a[i].fi) ; 
		a[i].se=abs(a[i].se);
	}

	sort(a+1,a+1+n) ; 

	deque<int> dq ; 
	int sz = 0 ; 
	FOR(i,1,n) {
		while(!dq.empty() and a[dq.front()].se < a[i].se) {
			dq.pop_front() ; 
			sz-- ; 
		}
		b[++sz] = a[i] ; 
		dq.push_front(i) ; 
	}

	FOR(i,1,sz) a[i] = b[i] ; 
	
	n = sz ;

	FOR(i,1,n) dp[i] = inf ; 

	FOR(i,1,n) {
		FOR(j,1,i) {
			if(a[i].se >= a[j].se) dp[i] = min(dp[i],dp[j-1] + a[i].se*a[i].fi ) ; 
			else dp[i] = min(dp[i],dp[j-1] + a[i].fi*a[j].se ) ; 
		}
	}	

	cout << dp[n]*4 ; 
}	

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}