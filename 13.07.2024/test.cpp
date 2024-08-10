#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;

int n,m ;
int a[maxn] ;
int cost[2005][2005] ; 
int cnt[maxn] ; 
ll dp[maxn][25] ; 
int best[maxn][2005] ; 

void mitsuri_read(void) {
	cin >> n >> m ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void DAC(int k,int L,int R,int opL,int opR) {
    if(L>R) return ;
    int mid = (L+R)>>1;
    FOR(i,opL,min(mid,opR)) {
        ll c = dp[i][k-1] + cost[i+1][mid] ; 
        if(dp[mid][k] > c) {
            dp[mid][k] = c ;
            best[mid][k] = i ;
        }
    }
    DAC(k,L,mid-1,opL,best[mid][k]);
    DAC(k,mid+1,R,best[mid][k],opR);
}

void mitsuri1_solve(void) {
	FOR(i,1,n) {
		int sum = 0 ; 
		FOR(j,i,n) {
			sum+=cnt[a[j]] ; 
			cost[i][j] = sum ; 
			cnt[a[j]]++ ; 
		} 
		FOR(j,i,n) cnt[a[j]] = 0 ;
	}	
	FOR(i,0,n) FOR(j,0,m) dp[i][j] = 1e18 ; 
	dp[0][0] = 0 ; 
	FOR(j,1,m) DAC(j,1,n,1,n) ; 	
	cout << dp[n][m] ; 
}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    mitsuri_read() ;
    mitsuri1_solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}