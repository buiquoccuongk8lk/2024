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
vii g[MAXN] ;
ii e[MAXN] ;
int res[MAXN] ;
int del[MAXN] ; // cạnh i bị xóa bởi truy vấn k
int f[MAXN] ; // số hiệu truy vấn lớn nhất mà khi đi xóa cung vào i
set<int> c[MAXN] ;
unordered_map<int,vi> T ; // danh sách những cạnh bị ảnh hưởng
struct Queries {
	int t , id ;
} Q[MAXN] ;
bool dd[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,m) {
		int u,v;cin>>u>>v ;
		e[i] = {u,v} ; 
		g[u].pb(ii(v,i)) ; 
		c[u].insert(i) ;
	}
	memset(del,0x3f,sizeof del) ;
	cin >> q ; 
	FOR(i,1,q) {
		int t , id ; cin >> t >> id ; 
		if(t==1) {
			del[id] = i ; 
		} 
		Q[i] = {t,id} ;
	}
}

void dijkstra() {
	priority_queue<ii,vector<ii>>pq ; 
	f[1] = oo ; 
	pq.push({f[1],1}) ;
	while(!pq.empty()) {
		int u = pq.top().se ; 
		int cost = pq.top().fi ; 
		pq.pop() ; 
		if(dd[u]) continue ; 
		dd[u] = 1 ; 
		if(f[u] < oo) T[f[u]].push_back(u) ;
		for(auto x : g[u]) {
			int v = x.fi , id = x.se ; 
			int w = min(del[id],cost) ; 
			res[v]++ ;
			if(f[v] < w) {
				f[v] = w ;
				pq.push({f[v],v}) ;
			} 
		}
	}
}	

void solve() {
	dijkstra() ;
	FOR(i,1,q) {
		for(auto x : T[i]) {
			for(auto id : c[x]) {
				int v = e[id].se ; 
				res[v]-- ; 
			}
		}
		if(Q[i].t==2) cout << res[Q[i].id] << '\n' ; 
		else {
			int id = Q[i].id ; 
			int u = e[id].fi , v = e[id].se ; 
			if(f[u] > i) {
				res[v]-- ; 
				c[u].erase(id) ;
			}
		}
	}
}	

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */