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
const int LO = __lg(maxn) + 1 ; 

int n , q ;
int a[maxn] ;
int rmq[maxn][LO] ;

int get(int l,int r) {
	int k = __lg(r-l+1) ; 
	return __gcd(rmq[l][k],rmq[r-(1<<k)+1][k]) ; 
}

void solve(void) {	
	
	FOR(i,1,n) rmq[i][0] = abs(a[i]) ; 
	
	for(int j(1) ; (1<<j) - 1 <= n ; j++) {
		for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
			rmq[i][j] = __gcd(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
		}
	}	

	unordered_map<int,int>mp ;

	FOR(r,1,n) {
		int l = 1 ; 
		while(l <= r) {
			int val = get(l,r) ; 
			int d = l ; 
			int c = r ;
			int pos = l ; 
			while(d <= c) {
				int mid = (d+c)>>1 ; 
				if(get(mid,r) == val) {
					d = mid + 1 ;
					pos = mid ; 
				} else c = mid - 1 ; 
			}
			mp[val]+= pos - l + 1 ;
			l = pos + 1 ; 
		}
	}

	while(q--) {
		int x ; cin >> x ; 
		cout << mp[x] << '\n' ; 
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
	FOR(i,1,n) cin >> a[i] ; 
	cin >> q ; 
	solve() ;     
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}