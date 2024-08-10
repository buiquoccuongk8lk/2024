#include <bits/stdc++.h>
using namespace std ;

using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 6e3 + 5 ;

int n,m ; 
int a[max_mitsurii] ;
int dp[max_mitsurii][55] ;
int cost[max_mitsurii][max_mitsurii] ; 
deque<int> dq[max_mitsurii] ;

void mitsuri_read(void) {
	cin >> n >> m ;
	FOR(i,1,n) cin >> a[i] ; 
	//cout << n << ' ' << m ; 
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
	if(m >= n) {
		cout << m ;
		return ; 
	}
	mitsuri_building() ; 
	FOR(i,0,n) FOR(j,0,m) dp[i][j] = -2e9 ; 
	FOR(i,0,n) dp[i][0] = 0 ;	
	FOR(i,1,n) dp[i][1] = cost[1][i] ; 
	FOR(k,2,m) DAC(k,1,n,1,n) ;
	cout << dp[n][m] ; 
}

signed main(void) {
    #define mitsurichannn "dcandy"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".ANS","w",stdout);
    }
 	mitsuri_read() ;
 	mitsuri2_solve() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}