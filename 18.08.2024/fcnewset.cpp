#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()

#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 1e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n , s , k ;

void init() {
	cin >> n >> s >> k ; 
}

/*namespace sub1 {

	int dp[55][2005] ;
	int sum[2005] ;

	void solve() {
		dp[0][0] = 1 ;
		FOR(i,1,k) {
			FOR(j,0,1000) sum[j] = (sum[j-1] + dp[i-1][j])%mod ;
			FOR(j,1,1000) {
				int u = n / j , v = s - j ; 
				dp[i][j] = (dp[i][j] + sum[min(u,v)])%mod ; 
			}
		}
		int ans = 0 ;
		FOR(j,0,1000) ans = (ans + dp[k][j])%mod ;
		cout << ans ; 
	}
}*/

namespace sub2 {
	vector < vector<int> > dp, sum ;
	void solve() {
		vi V ;
		V.pb(0) ;
		FOR(i,1,n/i) {
			V.pb(i) ;
			if(s - i) V.pb(s - i) ; 
			V.pb(n / i) ;
		}
		sort(all(V)) ; 
    	int m = V.size() ;
    	dp.resize(k+5,vector<int>(m+5,0)) ;
    	sum.resize(k+5,vector<int>(m+5,0)) ;
		FOR(i,1,V.size()-1) {
			dp[1][i] = V[i] - V[i-1] ; 
			sum[1][i] = (sum[1][i-1] + dp[1][i])%mod ;
		}
		FOR(i,2,k) {
			FOR(j,1,V.size()-1) {
				int u = upper_bound(all(V),n/V[j]) - V.begin() - 1 ;
				int v = upper_bound(all(V),s-V[j]) - V.begin() - 1 ;
				dp[i][j] = ( sum[i-1][max((int)0,min(u,v))] * (V[j] - V[j-1]) )%mod ; 
				sum[i][j] = (sum[i][j-1] + dp[i][j])%mod ;
			}
		}
		int ans = 0 ; 
		FOR(j,1,V.size()-1) ans = (ans + dp[k][j])%mod ;
		cout << ans ; 
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; 
    /*if(n <= 1000 && s <= 1000) sub1::solve() ;
    else */sub2::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}