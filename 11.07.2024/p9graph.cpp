#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 5e5 + 5 ;
const int oo = 2e9 ;

int n , m ; 
vector<int> undig[max_mitsurii] , dig[max_mitsurii] ; 
long long pre_dist[max_mitsurii],suf_dist[max_mitsurii] ; 
int ID[max_mitsurii] , mark[max_mitsurii] ;  

void mitsuri_read(void) {
	cin >> n >> m ;
	FOR(i,1,m) {
		int u,v ; 
		cin >> u >> v ; 
		undig[u].pb(v) ; 
		undig[v].pb(u) ; 
		dig[u].pb(v) ; 
	}
}

void BFS(int st,long long dist[]) {
	FOR(i,1,n) dist[i] = oo ; 
	deque<int> dq ; 
	dist[st] = 0 ; 
	dq.pb(st) ; 
	while(!dq.empty()) {
		int u = dq.front() ; 
		dq.pop_front() ; 
		for(auto v : undig[u]) {
			if(dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1 ; 
				dq.pb(v) ; 
			}
		}
	}
}

void mitsuri_solve(void) {
	BFS(1,pre_dist) ; 
	BFS(n,suf_dist) ; 
	FOR(i,1,n) ID[i] = i ; 
	sort(ID+1,ID+1+n,[](int u,int v) {
		return pre_dist[u] < pre_dist[v] ; 
	}) ; 	
	long long ans = oo ; 
	FOR(i,1,n) {
		int u = ID[i] ; 
		if(mark[u]) continue ; 
		mark[u] = 1 ; 
		deque<int> dq ; 
		dq.pb(u) ; 
		while(!dq.empty()) {
			int x = dq.front() ;
			dq.pop_front() ; 
			ans = min(ans,pre_dist[u] + suf_dist[x]) ; 
			for(auto v : dig[x]) {
				if(!mark[v]) {
					dq.pb(v) ; 
					mark[v] = 1 ; 
				}
			}
		}
	}
	cout << (ans >= oo ? -1 : ans) ;
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