#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 5e3 + 5 ;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r) {
    return l + rd()%(r-l+1);
}

int n,m ; 
int a[max_mitsurii] ;
int dp[max_mitsurii][55] ;
int cost[max_mitsurii][max_mitsurii] ; 
deque<int> dq[max_mitsurii*10] ;

void mitsuri_read(void) {
	cin >> n >> m ;
	FOR(i,1,n) cin >> a[i] ; 
	/*n = Rand(4,8) ; 
	m = Rand(3,min(50,n)) ;
	cout << n << ' ' << m << endl  ;
	FOR(i,1,n) {
		a[i] = Rand(n-4,n) ;
		cout << a[i] << ' ' ;
	}
	cout << endl ;*/
}

void mitsuri_building(void) {
	FOR(i,1,n) {
		cost[i][i] = 1 ; 
		dq[a[i]].pb(i) ; 
		FOR(j,i+1,n) {
			cost[i][j] = cost[i][j-1] + (dq[a[j]].empty() || dq[a[j]].back() < i) ; 
			if(dq[a[j]].size()) dq[a[j]].pop_front() ; 
			dq[a[j]].pb(j) ; 
		}
		FOR(j,i,n) dq[a[j]].clear() ; 
	}
}

void mitsuri1_solve(void) {	
	mitsuri_building() ; 
	FOR(i,0,n) FOR(j,0,m) dp[i][j] = -2e9 ; 
	FOR(i,0,n) dp[i][0] = 0 ;
	FOR(i,1,n) dp[i][1] = cost[1][i] ;
	FOR(i,1,n) FOR(j,1,m) {
		FOR(v,1,i-1) {
			dp[i][j] = max(dp[i][j],dp[v][j-1] + cost[v+1][i]) ; 
		}
	}
	cout << dp[n][m] ;
}

int best[max_mitsurii][max_mitsurii];
void DAC(int k,int L,int R,int opL,int opR) {
    if(L>R) return ;
    int mid = (L+R)>>1;
    FOR(i,opL,min(mid,opR)) {
        int c = dp[i][k-1] + cost[i+1][mid] ;
        if(dp[mid][k] < c) {
            dp[mid][k] = c;
            best[mid][k] = i;
        }
    }
    DAC(k,L,mid-1,opL,best[mid][k]);
    DAC(k,mid+1,R,best[mid][k],opR);
}

void mitsuri2_solve(void) {
	mitsuri_building() ; 
	FOR(i,0,n) FOR(j,0,m) dp[i][j] = -2e9 ; 
	FOR(i,0,n) dp[i][0] = 0 ;	
	FOR(i,1,n) dp[i][1] = cost[2][i] ; 
	FOR(k,2,m) DAC(k,1,n,1,n) ;
	cout << dp[n][m] ; 
}

signed main(void) {
    #define mitsurichannn "dcandy"
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