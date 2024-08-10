#include <bits/stdc++.h>
using namespace std ; 
#define int long long
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int maxn = 1e5 + 5 ;

int n ; 
struct DL {
	int x,y,w ; 
} a[maxn] , b[maxn] ;
ll pre[maxn] , dp[maxn] ; 

void mitsuri_read(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].x >> a[i].y >> a[i].w ; 
}

void mitsuri_solve(void) {
	sort(a+1,a+1+n,[](DL u,DL v) {
		if(u.x==v.x and u.y==v.y) return u.w > v.w ; 
		else if(u.x==v.x) return u.y > v.y ; 
		else return u.x < v.x ; 
	}) ; 
	FOR(i,1,n) dp[i] = -1e18 ; 
	dp[0] = 0 ;
	FOR(i,1,n) {
		dp[i] = a[i].x*a[i].y - a[i].w ; 
		FOR(j,1,i) {
			dp[i] = max(dp[i],dp[j] + (a[i].x - a[j].x)*a[i].y - a[i].w) ; 
		}
	}
	cout << *max_element(dp+1,dp+1+n) ; 
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
