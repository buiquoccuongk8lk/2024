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
const int inf = 1e18 ;

int n , k , m , t ;
int a[1005][1005] ;

namespace sub1 {

	int f[1005][1005] ;
	int HCN(int x,int y,int u,int v) {
		return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1] ; 
	}

	void solve(void) {
		
		FOR(i,1,n) FOR(j,1,m) {
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j] ; 
		}

		int ans = 0 ;  
		FOR(i,1,n) FOR(j,1,m) {
			int l = 1 ; 
			int r = min(n - i + 1 , m - j + 1); 
			int x = 0 ; 
			while(l <= r) {
				int mid = (l+r)>>1 ; 
				ll sum = HCN(i,j,i+x-1,j+x-1) ;
				if(sum <= t) x = mid , l = mid + 1 ; 
				else r = mid - 1 ; 
			}
			if( HCN(i,j,i+x-1,j+x-1) <= t ) ans = max(ans,x) ; 
		}
		cout << ans * ans ; 
	}

}
namespace sub2 {

	int f[305][305] ;
	int HCN(int x,int y,int u,int v) {
		return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1] ; 
	}
	int dp[305][305][305] ; // tổng nhỏ nhất có kích thước len có diện tích lớn nhất có tọa độ (1,1,i,j)

	void solve(void) {
		
		FOR(i,1,n) FOR(j,1,m) {
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j] ; 
		}

		ll ans = 0 ; 

		FOR(i,0,n) FOR(j,0,m) FOR(len,0,min(n,m)) dp[i][j][len] = inf ;

		FOR(i,1,n) FOR(j,1,m) FOR(len,1,min(i,j)) {
			dp[i][j][len] = min( dp[i][j][len], HCN(i-len+1,j-len+1,i,j) ) ;
			dp[i][j][len] = min( dp[i][j][len], dp[i-1][j][len] ) ; 
			dp[i][j][len] = min( dp[i][j][len], dp[i][j-1][len] ) ;  
		}

		FOR(i,1,n) FOR(j,1,m) FOR(len,1,min(i,j)) {	
			ll sum = HCN(i-len+1,j-len+1,i,j) ; 
			if(sum > t) break ; 
			int r = max(i-len,j-len) ; 
			int l = 1 ; 
			int x = 0 ;
			while(l + 1 < r) {
				int mid = (l+r)>>1 ;
				ll sum2 = min(dp[n][j-len][mid],dp[i-len][m][mid]) ; 
				if(sum2+sum<=t) l = mid ; 
				else r = mid ; 
			}
			ll sum2 = min(dp[n][j-len][r],dp[i-len][m][r]) ; 
			if(sum2 + sum <= t) {
				x = r ; 
				if(x > 0) ans = max(ans , len * len + x *x ) ;
			}
			sum2 = min(dp[n][j-len][l],dp[i-len][m][l]) ;
			if(sum2 + sum <= t) x = l ; 
			if(x > 0) ans = max(ans , len * len + x *x ) ;
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
    cin >> n >> m >> k ; 
    cin >> t ; 
    FOR(i,1,n) FOR(j,1,m) cin >> a[i][j] ; 
    if(k == 1) sub1::solve() ;  
    else sub2::solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}