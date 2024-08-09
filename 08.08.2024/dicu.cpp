/*[продолжатьипродолжать]*/


#include <bits/stdc++.h>

using namespace std ; 
const int MAX = 1e6 + 5 ;
const int dx[] ={0 , 0 , 0 , 0 , -1  , 1} ; 
const int dy[] ={0 , 0 , 1 , -1 , 0 , 0 } ;

int n , m ;
vector<vector<char>> a ;
unordered_map<char,int> mp ;
unordered_map<int,int> dp[MAX][10] ;

void init(void) {
	cin >> n >> m ;
	a.resize(n+2,vector<char>(m+2,'8')) ;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++) 
			cin >> a[i][j] ; 
}

struct PQ {
	int u , v , t , cost ; 
	bool operator <(const PQ &e) const {
		return cost > e.cost ; 
	}
} ;
int change(char x) {
	if(x=='o') return 1 ; 
	if(x=='>') return 2 ; 
	if(x=='<') return 3 ; 
	if(x=='^') return 4 ; 
	if(x=='v') return 5 ; 
	if(x=='.') return 6 ; 
	if(x=='x') return 7 ;
	return 0 ; 
}

void solve(void) {
	priority_queue<PQ,vector<PQ>>pq ; 
	pair<int,int> st ;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++) if(a[i][j]=='o') st = {i,j} ; 

	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++) 
			for(int t = 0 ; t <= 7 ; t++) dp[i][t][j] = 2e9 ;

	dp[st.first][change('o')][st.second] = 0 ; 
	pq.push({st.first , st.second , change('o') , 0}) ;

	while(!pq.empty()) {
		int u = pq.top().u ; 
		int v = pq.top().v ; 
		int t_cur = pq.top().t ; 
		int cost = pq.top().cost ; 
		pq.pop() ; 
		if(cost > dp[u][t_cur][v]) continue ; 

		if(t_cur==1) {
			for(int t_new = 2 ; t_new <= 5 ; t_new++) {
				int x = u + dx[t_new] ; 
				int y = v + dy[t_new] ; 
				int t = t_cur ; 
				if(x < 1 || x > n || y < 1 || y > m) continue ; 
				if(a[x][y]=='.') {
					if(dp[x][change(a[x][y])][y] > dp[u][t][v] + 1) {
						dp[x][change(a[x][y])][y] = dp[u][t][v] + 1 ;
						pq.push({x , y ,change(a[x][y]) , dp[x][change(a[x][y])][y]}) ; 
					}
				}
			}
		} 

		for(int t_new = 2 ; t_new <= 5 ; t_new++) {
			int x = u + dx[t_new] ; 
			int y = v + dy[t_new] ; 
			int t = t_cur ; 
			if(x < 1 || x > n || y < 1 || y > m) continue ; 
			int w = (t != t_new && t!=1) ; 
			if(dp[x][change(a[x][y])][y] > dp[u][t][v] + w) {
				dp[x][change(a[x][y])][y] = dp[u][t][v] + w ;
				pq.push({x , y , change(a[x][y]) , dp[x][change(a[x][y])][y]}) ; 
			}
		}

	}

	int ans = 2e9 ; 

	pair<int,int> ed ; 

	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++) if(a[i][j]=='x') ed = {i,j} ;

	for(int t = 2 ; t <= 7 ; t++) ans = min(ans , dp[ed.first][t][ed.second]) ;  
	cout << ans ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}