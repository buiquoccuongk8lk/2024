/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e4 + 5 ;

int n,L1,L2,C,D ;
int a[4*MAX] ; 

void init(void) {
	cin >> n >> L1 >> L2 >> C >> D ; 
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 
}

namespace sub1 {
	bool check() {return L1==L2 ;}
	void solve(void) {
		int L = L1 ;
		long long ans = 0 ;
		while(1) {
			int i = n ;
			for(int j = 1 ; j <= n ; j++) {
				if(a[j]!=L) {
					i = j ; 
					break ; 
				}
			}
			if(i==n && a[i]==L) {
				break ; 
			}
			if(a[i] > L) {
				n++ ; 
				for(int j = n ; j >= i + 2 ; j--) a[j] = a[j-1] ; 
				a[i+1] = a[i] - L ; a[i] = L ; 
				ans+= C ;
			} else if(a[i] < L) {
				a[i]+= a[i+1] ; 
				for(int j = i + 1 ; j <= n ; j++) a[j] = a[j+1] ; 
				n-- ;
				ans+= D ; 
			}
		}
		cout << ans ; 
	}
}

namespace sub3 {
	bool check() {return n <= 100 && L1 <= 100 && L2 <= 100 && *max_element(a+1,a+1+n) <= 100; }
	long long dp[105][10005] ;
	void solve(void) {
		long long S = 0 ;
		for(int i = 1 ; i <= n ; i++) S+=a[i] ; 
		for(int i = 1 ; i <= n ; i++) for(int j = 0 ; j <= S ; j++) dp[i][j] = 1e18 ; 
		dp[0][0] = 0 ;
		for(int i = 0 ; i <= n ; i++) {
			for(int j = S ; j ; j--) {
				if(j + a[i] <= S) dp[i+1][j + a[i]] = min(dp[i+1][j + a[i]],dp[i][j] + C) ;
				if(j >= L1) dp[i][j-L1] = min(dp[i][j-L1],dp[i][j] + D * (j == 0 ? 0 : 1) ) ; 
				if(j >= L2) dp[i][j-L2] = min(dp[i][j-L2],dp[i][j] + D * (j == 0 ? 0 : 1) ) ;  
			}
		}
		cout << dp[n][0] ;
	}
}

signed main(void) {
    #define watbor "WPRO"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(watbor".inp","r") ) {
        freopen(watbor".inp","r",stdin) ; freopen(watbor".out","w",stdout);
    }
    init() ;
    /*if(sub1::check()) sub1::solve() ; 
    else*/ sub3::solve() ; 
    cerr << endl << "WatborLAT : " << clock() << "ms" << endl;
    return 0 ;
}