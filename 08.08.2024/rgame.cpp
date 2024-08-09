#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 1000005
typedef long long ll ;

int n ;
int a[MAXN] ; 

void init() {
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
}

namespace sub1 {
    double dp[105][105] ; 
    double calc(short l,short r) {
        if(l==r) return 0 ;
        if(dp[l][r]!=-1) return dp[l][r] ; 
        dp[l][r] = 0 ; 
        maxi(dp[l][r],calc(l+1,r)+a[l+1]);
        maxi(dp[l][r],calc(l,r-1)+a[r-1]) ; 
        for(short k = l + 1 ; k <= r - 1 ; k++) 
            maxi(dp[l][r],calc(l,k-1) + calc(k+1,r) + (double)(a[k-1]+a[k+1])/2) ;
        return dp[l][r] ;   
    }
    void solve() {
        FOR(i,1,n)FOR(j,1,n)dp[i][j] = -1 ;        
        FOR(i,1,n) dp[i][i] = 0 ;
        FOR(i,1,n-1) dp[i][i+1] = max(a[i],a[i+1]) ; 
        cout << fixed << setprecision(1) << calc(1,n) << '\n' ; 
    }
}

namespace sub2 {

    void solve() {

    }
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int t ; cin >> t ; 
    while(t--) {
        init() ; 
        //if(n <= 80) sub1::solve() ; 
        sub2::solve() ; 
    }
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}