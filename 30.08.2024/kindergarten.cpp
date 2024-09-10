// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1e6 + 5 ;

int n ; 
int a[MAXN] , dp[MAXN][3] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

// gọi dp[i][0/1/2] là tổng lớn nhất khi xếp i thằng đầu và
// 0 là chưa chọn xong
// 1 là đã chọn thằng lớn nhất
// 2 là đã chọn thằng nhỏ nhất
// 3 là đã chọn xong nhỏ nhất và lớn nhất

void solve() {
	if(n == 1) {
		cout << 0 ; 
		exit(0) ;
	}
	memset(dp,-0x3f,sizeof dp) ;	
	dp[0][0] = 0 ;
	FOR(i,1,n) {
		dp[i][0] = max(dp[i-1][3],1ll*0) ; 
		dp[i][1] = max({dp[i-1][0]+a[i],dp[i-1][3]+a[i],dp[i-1][1]}) ; 
		dp[i][2] = max({dp[i-1][0]-a[i],dp[i-1][3]-a[i],dp[i-1][2]}) ; 
		dp[i][3] = max({dp[i-1][1]-a[i],dp[i-1][2]+a[i],dp[i-1][3],dp[i-1][0]}) ; 
	}
	cout << dp[n][3] ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */