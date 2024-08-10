#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 3e3 + 5 ;
const ll inf = 1e18 ; 

int n ; 
int a[max_mitsurii] ;
ll dp[max_mitsurii][max_mitsurii],pre[max_mitsurii] ; 
int range[max_mitsurii][max_mitsurii] ;  

void mitsuri_read(void) {
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
}

void mitsuri1_solve(void) {
    FOR(i,0,n) FOR(j,0,n) dp[i][j] = inf ; 
    FOR(i,0,n) {
        dp[i][i] = 0 ; 
    }
    FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 
    FOR(r,1,n) {
        FORD(l,r-1,1) {
            FOR(k,l,r-1) {
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+(pre[r] - pre[l-1])*(pre[r]-pre[l-1])) ; 
            }
        }
    }
    cout << dp[1][n] ;
}

void mitsuri2_solve(void) {
    FOR(i,0,n) FOR(j,0,n) dp[i][j] = inf ; 
    FOR(i,0,n) {
        dp[i][i] = 0 ; 
        range[i][i] = i ;
    }   
    FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 
    FOR(r,1,n) {
        FORD(l,r-1,1) {
            FOR(k,range[l][r-1],range[l+1][r]) {
                if( dp[l][k] + dp[k+1][r] + (pre[r]-pre[l-1])*(pre[r]-pre[l-1]) < dp[l][r] ) {
                    dp[l][r] = dp[l][k] + dp[k+1][r] + (pre[r]-pre[l-1])*(pre[r]-pre[l-1]) ; 
                    range[l][r] = k ; 
                }
            }
        }
    }
    cout << dp[1][n] ;
}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    mitsuri_read() ;
    if(n <= 500) mitsuri1_solve() ; 
    else mitsuri2_solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}