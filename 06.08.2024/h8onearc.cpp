#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
using namespace std ; 

const int N = 1e5 + 5 ;

int n , m ;
vector<int> g[N] ; 
int low[N] , num[N] , vis[N] , par[N] , degIn[N] , degOut[N] ;
int timeDFS , scc , ssc ; 
int sccID[N] ; 
deque<int> dq ; 
	
void tarjan(int u) {
	low[u] = num[u] = ++timeDFS ; 
	dq.push_back(u) ;
	for(auto v : g[u]) {
		if(vis[v]) continue ; 
		if(num[v] > 0) low[u] = min(low[u],num[v]) ; 
		else {
			par[v] = u ;
			tarjan(v) ; 
			low[u] = min(low[u],low[v]) ; 
		}
	}
	if(low[u] == num[u]) {
		scc++ ; 
		int x ;
		do {	
			x = dq.back() ; 
			vis[x] = 1 ; 
			sccID[x] = scc ;
			dq.pop_back() ; 
		} while(x!=u) ; 
	}
}

void solve() {
	for(int i(1) ; i <= n ; i++) if(!num[i]) tarjan(i) ;
	for(int u(1) ; u <= n ; u++) {
		for(auto v : g[u]) {
			int x = sccID[u] ; 
			int y = sccID[v] ; 
			if(x!=y) {
				degOut[x]++ ;
				degIn[y]++ ; 
			}
		}
	}
	int ans = 0 ; 
	for(int i(1) ; i <= scc ; i++) {
		if(degOut[i]==0) ans++ ; 
	} 
	int ans1 = 0 ;
	for(int i(1) ; i <= scc ; i++) {
		if(degIn[i]==0) ans1++ ; 
	} 
	cout << ( (ans == 1 && ans1 == 1) ? "YES" : "NO") ; 
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
	cin >> n >> m ; 
	for(int i(1) ; i <= m ; i++) {
		int u , v ; cin >> u >> v ; 
		g[u].push_back(v) ; //g[v].push_back(u) ; 
	}    
	solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}