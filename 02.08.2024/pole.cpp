#include<bits/stdc++.h>
using namespace std ;
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
const int N = 1e4 + 5 ; 
const int M = 2e3 + 5 ; 
typedef long long ll ;

int n , c ; 
int a[N] ;

namespace subtask1 {
	bool check() {
		FOR(i,1,n)if(a[i] > 100) return 0 ; 
		return 1 ;
	}
	ll dp[1005][505] ;
	void solve() {
		memset(dp,0x3f3f3f,sizeof dp) ; 	
		dp[0][0] = 0 ;	
		FOR(ch,0,500)dp[0][ch] = 0 ;
		FOR(i,1,n) FOR(ch,a[i],500) {
			FOR(pch,a[i-1],500) {
				dp[i][ch] = min(dp[i][ch],dp[i-1][pch] + abs(a[i] - ch) * abs(a[i] - ch) + c * abs(ch - pch) ) ; 
			}
		}
		ll ans = 1e18 ; 
		FOR(ch,0,500) ans = min(ans,dp[n][ch]) ; 
		cout << ans ; 
	}
}

namespace subtask2 {
	ll dp[N][M] ;
	ll pre[M],suf[M] ; 
	void solve() {
		memset(dp,0x3f3f3f,sizeof dp) ; 	
		dp[0][0] = 0 ; 
		FOR(ch,0,2000)dp[0][ch] = pre[ch] = suf[ch] = 0 ; 
		FOR(i,1,n) {
			FOR(ch,0,2000) pre[ch] = suf[ch] = 1e18 ; 
			FOR(ch,1,2000) pre[ch] = min(pre[ch-1],dp[i-1][ch] - c * ch) ; 
			FORD(ch,1999,0) suf[ch] = min(suf[ch+1],dp[i-1][ch] + c * ch) ;  
			FOR(ch,a[i],1000) {
				dp[i][ch] = pre[ch] + c * ch + abs(a[i] - ch) * abs(a[i] - ch) ; 
				dp[i][ch] = min(dp[i][ch] , suf[ch] - c * ch + abs(a[i] - ch) * abs(a[i] - ch) ) ; 
			}	
		}
		ll ans = 1e18 ; 
		FOR(ch,0,2000) ans = min(ans,dp[n][ch]) ; 
		cout << ans ; 
	}	
}
signed main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ; 
	//freopen(".inp","r",stdin) ; 
	//freopen(".out","w",stdout) ;
	cin >> n >> c ; 
	FOR(i,1,n) cin >> a[i] ;
	if(subtask1::check()) subtask1::solve() ; 
	else subtask2::solve() ;
	return 0 ; 
}