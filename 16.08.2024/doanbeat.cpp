#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)
template<class X,class Y> bool maxi(X &x,const Y &y) {if(x < y){x = y ; return 1;}else return 0;}
template<class X,class Y> bool mini(X &x,const Y &y) {if(x > y){x = y ; return 1;}else return 0;}
using namespace std ; 
#define MAXN 105 

int n ;
int a[MAXN] , b[MAXN] , c[MAXN] ;
__int128 dp[MAXN][MAXN][MAXN] ; 

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) cin >> b[i] ; 
	FOR(i,1,n) cin >> c[i] ; 
}

void truyvet(int i,int j,int t,int len) {
	if(!i && !j && !t) {
		cout << len << endl ; 
		return ; 
	}
	if(i && j && t && a[i]==b[j] && a[i]==c[t] && (__int128)dp[i-1][j-1][t-1]*a[i]==dp[i][j][t]) {
		truyvet(i-1,j-1,t-1,len+1) ; 
		cout << a[i] << ' ' ;
	} else if(i && dp[i-1][j][t] == dp[i][j][t]) {
		truyvet(i-1,j,t,len) ; 
	} else if(j && dp[i][j-1][t] == dp[i][j][t]) {
		truyvet(i,j-1,t,len) ; 
	} else if(t && dp[i][j][t-1] == dp[i][j][t]) {
		truyvet(i,j,t-1,len) ; 
	} 
}

void solve() {	
	FOR(i,0,n)FOR(j,0,n)FOR(t,0,n)dp[i][j][t] = -0x3f3f3f ; 
	FOR(j,0,n)FOR(t,0,n)dp[0][j][t] = 1 ;
	FOR(i,0,n)FOR(t,0,n)dp[i][0][t] = 1 ;
	FOR(i,0,n)FOR(j,0,n)dp[i][j][0] = 1 ;
	dp[0][0][0] = 1 ; 
	FOR(i,1,n) FOR(j,1,n) FOR(t,1,n) {
		__int128 &val = dp[i][j][t] ; 
		val = max({val , dp[i-1][j][t] , dp[i][j-1][t] , dp[i][j][t-1]}) ; 
		if(a[i]==b[j] && a[i]==c[t]) maxi(val,(__int128)dp[i-1][j-1][t-1]*a[i]) ; 
	}
	int bestA = -1 , bestB = -1 , bestC = -1 ; 
	int ma = 0 ; 
	FOR(i,1,n)FOR(j,1,n)FOR(t,1,n)if(maxi(ma,dp[i][j][t])) bestA = i , bestB = j , bestC = t ; 
	truyvet(bestA,bestB,bestC,0) ;
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