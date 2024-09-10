// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 2e5 + 5 ;
const int oo = 2e9 ;

int n , m , q ;
ii e[MAXN] ; 

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) cin >> e[i].fi >> e[i].se ; 
	cin >> q ; 
}

namespace subtask_1 {
	int adj[5005][5005] ; 
	int res[MAXN] , dist[MAXN] , degIn[MAXN] ;

	void bfs(int st) {
		FOR(i,1,n)dist[i] = 2e9 ; 
		queue<int> q ;
		q.push(1) ; 
		dist[1] = 0 ; 
		while(!q.empty()) {
			int u = q.front(); 
			q.pop() ; 
			FOR(v,1,n) if(adj[u][v] > 0) {
				if(mini(dist[v],dist[u]+1)) q.push(v) ; 
			}
		}
		FOR(i,1,n) res[i] = 0 ;
		FOR(i,1,m) {
			int u = e[i].fi , v = e[i].se ; 
			if(adj[u][v] > 0 && dist[v]!=oo) res[v]++ ;
		}
	}

	void solve() {
		FOR(i,1,m) adj[e[i].fi][e[i].se]++ ; 
		bfs(1) ; 
		while(q--) {
			int t ; cin >> t ;
			if(t==1) {		
				int id ; cin >> id ; 
				int u = e[id].fi , v = e[id].se ; 
				adj[u][v]-- ; 
				if(adj[u][v]==0) {
					bfs(1) ; 
				} else {
					if(dist[v]!=oo) res[v]-- ; 
				}
			} else {
				int u ; cin >> u ;
				cout << res[u] << '\n' ; 
			}
		}
	}
}

namespace subtask_2 {

	void solve() {


	}

}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    subtask_1::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */