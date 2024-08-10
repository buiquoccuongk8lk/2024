#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define int short 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

template <class X,class Y> bool minimize(X &x, const Y &y) {
	if(x > y) {
		x = y ; 
		return true ; 
	} else return false ; 
}

const int dx[] = { 0 , 0 , -1 , 1 } ; 
const int dy[] = { -1 , 1 , 0 , 0 } ; 

const int maxn = 500 + 5 ; 
const int oo = 30000 ; 

int n,m ;
int a[maxn][maxn] , cost[maxn][maxn] ;
int ans , lim ; 
int L[maxn][maxn] , R[maxn][maxn] ; 
int dp[maxn][maxn][3][3] ;  

struct BG {
	int u,v,l,r ;
} ; 
queue<BG> q[9010] ;
struct BG2 {
	int u,v ; 
} ;
queue<BG2> Q[9010] ; 

void bfs_L(int s) {
	FOR(i,1,n) FOR(j,1,m) cost[i][j] = abs(a[i][j] - s) ; 
	FOR(i,1,n) FOR(j,1,m) L[i][j] = oo ; 
	FOR(i,1,n) {
		L[i][1] = cost[i][1] ; 
		Q[L[i][1]].push({ i , 1 }) ; 
	}
	FOR(val,0,ans) {
		while(!Q[val].empty()) {	
			int u = Q[val].front().u ; 
			int v = Q[val].front().v ; 
			Q[val].pop() ; 
			FOR(t,0,3) {
				int x = u + dx[t] ; 
				int y = v + dy[t] ; 
				if(x<1 || x>n || y<1 || y>m) continue ; 
				if(minimize(L[x][y] , L[u][v] + cost[x][y])) {
					Q[L[x][y]].push({x , y}) ; 
				}
			}
		}
	}
}

void bfs_R(int s) {
	FOR(i,1,n) FOR(j,1,m) cost[i][j] = abs(a[i][j] - s) ; 
	FOR(i,1,n) FOR(j,1,m) R[i][j] = oo ; 
	FOR(i,1,n) {
		R[i][m] = cost[i][m] ; 
		Q[R[i][m]].push({ i , m }) ; 
	}
	FOR(val,0,ans) {
		while(!Q[val].empty()) {	
			int u = Q[val].front().u ; 
			int v = Q[val].front().v ; 
			Q[val].pop() ; 
			FOR(t,0,3) {
				int x = u + dx[t] ; 
				int y = v + dy[t] ; 
				if(x<1 || x>n || y<1 || y>m) continue ; 
				if(minimize(R[x][y] , R[u][v] + cost[x][y])) {
					Q[R[x][y]].push({x , y}) ; 
				}
			}
		}
	}
}

void bfs_f(int s) {
	FOR(i,1,n) FOR(j,1,m) FOR(t1,0,1) FOR(t2,0,1) dp[i][j][t1][t2] = oo ; 
	FOR(i,1,n) FOR(j,1,m) cost[i][j] = abs(a[i][j] - s) ; 
	FOR(j,1,m) {
		if(j==1) {
			dp[1][j][1][0] = cost[1][j] ; 
			q[dp[1][j][1][0]].push({ 1 , j , 1 , 0 }) ; 
		} else if(j==m) {
			dp[1][j][0][1] = cost[1][j] ; 
			q[dp[1][j][0][1]].push({ 1 , j , 0 , 1 }) ; 
		} else {
			dp[1][j][0][0] = cost[1][j] ; 
			q[dp[1][j][0][0]].push({ 1 , j , 0 , 0 }) ; 
		}
	}
	FOR(val,0,ans) {
		while(!q[val].empty()) {
			auto [u,v,l,r] = q[val].front() ; 
			q[val].pop() ; 
			if(l==0 and minimize(dp[u][v][1][r],dp[u][v][l][r] + L[u][v] - cost[u][v])) {
				q[dp[u][v][1][r]].push({ u ,v , 1 , r }) ; 
			}
			if(r==0 and minimize(dp[u][v][l][1],dp[u][v][l][r] + R[u][v] - cost[u][v])) {
				q[dp[u][v][l][1]].push({ u ,v , l , 1 }) ; 
			}
			FOR(t,0,3) {
				int x = u + dx[t] ; 
				int y = v + dy[t] ; 
				if(x<1 || x>n || y<1 || y>m) continue ; 
				if(minimize(dp[x][y][l][r],dp[u][v][l][r]+cost[x][y])) {
					q[dp[x][y][l][r]].push({x , y , l , r}) ; 
				}
			}
		}
	}
}

void solve(void) {

	ans = (n + m) * 9 ;

	FOR(s,0,9) {
		bfs_L(s) ; 
		bfs_R(s) ; 
		bfs_f(s) ; 
		FOR(j,1,m) minimize(ans,dp[n][j][1][1]) ; 
	}
	cout << ans ; 
	
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> m ; 
    FOR(i,1,n) FOR(j,1,m) {
    	char x ; cin >> x ; 
    	a[i][j] = x - '0' ; 
    }
    solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}