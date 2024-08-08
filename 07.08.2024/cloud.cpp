#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 2005
#define MAXM 2005

int n , m ;
struct DL {
	int c , f , v ; 
	bool operator <(const DL &x) const {
		return f > x.f ; 
	}
} a[MAXN] , b[MAXM] ; 
long long dp[2][2005][205] ; 
//.dp[i][j][t] là số tiền lớn nhất khi xét 1...i , 1...j và có t món hàng

void init() {
	cin >> n ;
	FOR(i,1,n) cin >> a[i].c >> a[i].f >> a[i].v ;
	cin >> m ; 
	FOR(i,1,m) cin >> b[i].c >> b[i].f >> b[i].v ;
}
namespace subtask_1 {
	void solve() {
		sort(a+1,a+1+n) ; 
		sort(b+1,b+1+m) ; 

		FOR(i,0,n)FOR(j,0,m)FOR(t,0,200) dp[i&1][j][t] = -1e18 ; 
		dp[0&1][0&1][0] = 0 ; 

		FOR(i,0,n) {
			FOR(j,0,m) {
				FOR(t,0,200) {
					// không mua ngày 
					int nxt = (i+1)&1 ; 
					int now = i&1 ;

					maxi(dp[nxt][j][t],dp[now][j][t]) ; 
					// không bán ngày j
					maxi(dp[now][j+1][t],dp[now][j][t]) ; 

					// mua ngaỳ i
					if(t + a[i+1].c <= 200) {
						maxi(dp[nxt][j][t+a[i+1].c],dp[now][j][t] - a[i+1].v) ; 
					}

					// bán ngày i
					if(t >= b[j+1].c && a[i].f >= b[j+1].f) {
						maxi(dp[now][j+1][t-b[j+1].c],dp[now][j][t] + b[j+1].v) ; 
					}
				}
			}
		}	

		long long ans = 0 ;
	    FOR(j,0,m) FOR(t,0,100) {
			maxi(ans,dp[n&1][j][t]) ; 
		}
		cout << ans ; 
	}
}

signed main() {
    #define task "cloud"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; 
    subtask_1::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}