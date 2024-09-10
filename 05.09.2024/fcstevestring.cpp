#include<bits/stdc++.h>
using namespace std ;

template<class T> bool mini(T &a,const T &b) {
	if(a > b) {
		a = b ; 
		return 1 ; 
	}
	return 0 ;
}

const int MAXN = 1e2 + 5 ;

string s ;
int n ; 

void init() {
	cin >> s ; n = s.size() ; s = "*" + s ;
}

int dp[MAXN][4] ;
int can[MAXN][MAXN][4] ;

int Can(int l,int r,int ch) {
	if(l==r) return (s[l] - 'a' + 1 == ch) ; 
	if(can[l][r][ch]!=-1) return can[l][r][ch] ;
	int &val = can[l][r][ch] ; 
	val = 0 ; 
	int u , v ; 
	if(ch == 1) u = 2 , v = 3 ; 
	if(ch == 2) u = 1 , v = 3 ; 
	if(ch == 3) u = 1 , v = 2 ; 
	for(int k = l ; k <= r - 1 ; k++) {
		if(Can(l,k,u) && Can(k+1,r,v)) val = 1 ; 
		else if(Can(l,k,v) && Can(k+1,r,u)) val = 1 ; 
	}
	return val ;
}

void solve() {
	memset(dp,0x3f,sizeof dp) ;
	memset(can,-1,sizeof can) ;
	for(int ch = 1 ; ch <= 3 ; ch++) {
		dp[0][ch] = 0 ; 
		for(int i = 1 ; i <= n ; i++) 
			for(int j = 1 ; j <= i ; j++) 
				if(Can(j,i,ch)) mini(dp[i][ch],dp[j-1][ch]+1) ; 
	}
	cout << min({dp[n][1],dp[n][2],dp[n][3]}) << '\n' ;
}

signed main() {
	#define task ""
	if(fopen(task".inp","r")) {
		freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
	}
	int test ; cin >> test ;
	while(test--) {
		init() ; solve() ; 
	}
	cerr << "\nTIME :" << 0.001 * clock() << "s" ;
	return 0 ; 
}