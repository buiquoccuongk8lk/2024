#include <bits/stdc++.h>
using namespace std ; 
#pragma GCC optimize("O3")  
#pragma GCC optimize("unroll-loops")  
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt") 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 
const int maxn = 1e5 + 5 ;

int n , m ;
short a[4005][4005] ; 
int f[4005][4005],dp[4005][805] ; 
short best[4005][4005];

void mitsuri_read(void) {
	cin >> n >> m ; 
	FOR(i,1,n) FOR(j,1,n) cin >> a[i][j] ; 
}

int HCN(int x,int y,int u,int v) {
	return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1] ; 
}

void DAC(short k,short L,short R,short opL,short opR) {
    if(L>R) return ;
    short mid = (L+R)>>1;
    for(short i = opL ; i <= min(mid,opR) ; i++) {
        int cost = dp[i][k-1] + HCN(i+1,i+1,mid,mid)/2 ; 
        if(dp[mid][k] > cost) {
            dp[mid][k] = cost ;
            best[mid][k] = i ;
        }
    }
    DAC(k,L,mid-1,opL,best[mid][k]);
    DAC(k,mid+1,R,best[mid][k],opR);
}

void mitsuri_solve(void) {
	FOR(i,0,n) FOR(j,0,m) dp[i][j] = 2e9 ;
	dp[0][0] = 0 ; 
 	FOR(i,1,n) FOR(j,1,n) f[i][j] = f[i-1][j] + f[i][j-1] + a[i][j] - f[i-1][j-1] ;
 	FOR(i,1,n) dp[i][1] = HCN(1,1,i,i)/2 ; 
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
    mitsuri_solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}