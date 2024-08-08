#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 1005
#define MAXC 30
typedef long long ll ;

string s , t ; 
int n , m ;
struct BG {
	int x ;
	ll sl ; 
} a[MAXN] , b[MAXN] ; 
ll preA[MAXN][MAXC] , preB[MAXN][MAXC] ;
int parA[MAXC] , parB[MAXC] , ID[MAXC] ; 
ll dp[MAXN][MAXN] ; 

void init() {
	cin >> s ;
	cin >> t ; 
}

void build_rle() {
	FOR(i,0,(int)s.size()-1) {
		if(s[i] >= 'a' && s[i] <= 'z') {
			n++ ; 
			a[n].x = s[i] - 'a' ; 
		} else {
			a[n].sl = 1ll * a[n].sl * 10 + (s[i] - '0') ; 
		}
	}
	FOR(i,0,(int)t.size()-1) {
		if(t[i] >= 'a' && t[i] <= 'z') {
			m++ ; 
			b[m].x = t[i] - 'a' ; 
		} else {
			b[m].sl = 1ll * b[m].sl * 10 + (t[i] - '0') ; 
		}
	}		
	FOR(i,1,n) {
		parA[i] = ID[a[i].x] ; 
		ID[a[i].x] = i ;
	}
	memset(ID,0,sizeof ID) ; 
	FOR(i,1,m) {
		parB[i] = ID[b[i].x] ; 
		ID[b[i].x] = i ;
	}	
	FOR(t,0,27) {
		FOR(i,1,n) {
			preA[i][t] = preA[i-1][t] + (a[i].x == t) * a[i].sl ; 
		}
	}
	FOR(t,0,27) {
		FOR(i,1,m) {
			preB[i][t] = preB[i-1][t] + (b[i].x == t) * b[i].sl ; 
		}
	}
}

void solve() {
	build_rle() ; 
	FOR(i,1,n) FOR(j,1,m) {
		maxi(dp[i][j],dp[i-1][j]) ; 
		maxi(dp[i][j],dp[i][j-1]) ; 
		if(a[i].x == b[j].x) {
			int c = a[i].x , u = i , v = j ; 
			while(1) {
				if(preA[i][c] - preA[u-1][c] > preB[j][c] - preB[v-1][c]) {
					if(u && v) maxi(dp[i][j],dp[u-1][v-1] + preB[j][c] - preB[v-1][c]) ; 
					v = parB[v] ; 
					if(v==0) break ; 
				} else {
					if(u && v) maxi(dp[i][j],dp[u-1][v-1] + preA[i][c] - preA[u-1][c]) ; 
					u = parA[u] ; 
					if(u==0) break ; 
				}
			}
		}
	}
	cout << dp[n][m] ; 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}