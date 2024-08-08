#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 105
#define MAXK 35 

int n , k , m , len ;
int a[2*MAXN] ; 
int dp[2*MAXN][2*MAXN][2*MAXN] ; 
int pre[2*MAXN] ;

void init() { 
	cin >> n >> k ; 
	FOR(i,1,n) {
		char x ; cin >> x ; 
		a[i] = (x == 'R' ? 0 : 1) ; 
	}
}

int calc(int l,int r,int t) {
	int &is_win = dp[l][r][t] ; 
	if(t >= k) return 0 ;
	if(l==r) return (t + a[l] < k) ; 
	if(is_win!=-1) return is_win ; 
	int cur = pre[n] - (pre[r] - pre[l-1]) - t ; 
	is_win = 0 ;
	maxi(is_win,1 - calc(l+1,r,cur)) ; 
	maxi(is_win,1 - calc(l,r-1,cur)) ; 
	return is_win ; 
}

void solve() {
	FOR(i,1,n) a[i+n] = a[i] ; 
	FOR(i,1,2*n) pre[i] = pre[i-1] + a[i] ; 
	memset(dp,-1,sizeof dp) ;
	int ans = 0 ;
	FOR(i,1,n) ans+= ( calc(i,i+n-1,0) == 1 )  ;
	cout << ans ; 
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