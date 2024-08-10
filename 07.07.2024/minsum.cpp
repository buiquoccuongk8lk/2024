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
const int maxn = 1e5 + 5 ;
const ll inf = 1e18 ; 

int n ;
ll f[maxn] ; 

void solve(void) {
//	f[0] = 0 ;
	FOR(i,0,n) f[i] = inf ; 
	priority_queue<ii,vector<ii>,greater<ii>>pq ; 
	FOR(i,1,9) {
		f[i] = i ; 
		pq.push({f[i] , i%n}) ; 
	}
	while(!pq.empty()) {
		int u = pq.top().se ; 
		ll cost = pq.top().fi ; 
		pq.pop() ;
		if(cost > f[u]) continue ; 
		FOR(t,0,9) {
			int v = (u*10 + t)%n ;
			if(f[v] > f[u] + t) {
				f[v] = f[u] + t ; 
				pq.push({f[v],v}) ; 
			}
		}
	}
	cout << f[0] ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ;
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}