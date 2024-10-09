/* 29 . 03 . 2008 */

// hello a Hanh 
// chao Luat chao Fu 
# include <bits/stdc++.h>
using namespace std ; 

int n , k ;
int x[25] ;
long long a[505][505] , dist[505][505] ;
long long dp[25][1 << 20] ;
int t , i , j , mask ;

signed main() {
	#define task "banhkhuc" 
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
	cin >> n >> k ; 
	for(i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j] ; 
	
	for(i = 1 ; i <= k ; i++) cin >> x[i] ; 
	
	for(i = 1 ; i <= n ; i++) 
		for(j = 1 ; j <= n ; j++) dist[i][j] = a[i][j] ; 
		
	for(t = 1 ; t <= n ; t++) for(i = 1 ; i <= n ; i++)
		for(j = 1 ; j <= n ; j++)
			dist[i][j] = min(dist[i][j],dist[i][t] + dist[t][j]) ;

	for(mask = 0 ; mask < (1 << k) ; mask++) 
		for(i = 0 ; i < k ; i++) dp[i][mask] = 2e9 ;

	for(i = 0 ; i < k ; i++) {
		dp[i][1<<i] = dist[1][x[i+1]] ; 
	}

	for( mask = 0 ; mask < (1 << k) ; mask++) {
		for( i = 0 ; i < k ; i++) if((mask>>i)&1) {
			for( j = 0 ; j < k ; j++) if((mask>>j)&1 && i!=j) {
				dp[i][mask] = min(dp[i][mask],dp[j][mask^(1<<i)] + dist[x[j+1]][x[i+1]]) ; 
			}
		}
	}	

	long long ans = 1e18 ; 
	for( mask = 0 ; mask < (1 << k) ; mask++) {
		if(__builtin_popcount(mask)!=k) continue ; 
		for( i = 0 ; i < k ; i++) if((mask >> i) & 1) 
			ans = min(ans,dp[i][mask] + dist[x[i+1]][1]) ;
	}
	cout << ans ;
	return 0 ; 	
}