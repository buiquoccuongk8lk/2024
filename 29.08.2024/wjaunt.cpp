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

const int MAXN = 3e5 + 5 ;

int n , k , p ;
vii g[MAXN] ;
int h1[MAXN] , h2[MAXN] ; 
map<int,set<pair<int,int>>> zip[MAXN] ;

void init() {
	cin >> n >> p >> k ; 
	FOR(i,1,n-1) {
		int u,v,w; cin>>u>>v>>w ;
		g[u].pb(ii(v,w)) ; g[v].pb(ii(u,w)) ;
	}
}

void dfs(int u,int par) {
	zip[u][h2[u]].insert({h1[u],u}) ;
	for(auto x : g[u]) {
		int v = x.fi , w = x.se ; 
		if(v==par) continue ; 
		h1[v] = h1[u] + 1 ; 
		h2[v] = h2[u] + w ;  
		dfs(v,u) ;
	}
}

int node1 , node2 ;

void SML(int u,int par) {
	int target = p + 2 * h2[u] ; 
	for(auto x : g[u]) {
		int v = x.fi ; 
		if(v==par) continue ;
		SML(v,u) ;
		if(zip[v].size()>zip[u].size())swap(zip[u],zip[v]) ; 
		for(auto i : zip[v]) {
			if(zip[u].find(target-i.fi)==zip[u].end()) continue ;
			for(auto len : zip[v][i.fi]) {
				int len_v = len.fi ; 
				auto it = zip[u][target - i.fi].lower_bound({k + 2*h1[u] - len_v,0}) ;
				if(it!=zip[u][target - i.fi].end()) {
					int len_u = (*it).fi ; 
					if(len_u + len_v - 2 * h1[u] == k) {
						int cur_node1 = (*it).se ; 
						int cur_node2 = len.se ;
						if(cur_node1 > cur_node2) swap(cur_node1,cur_node2) ; 
						if(node1 == 2e9 && node2 == 2e9) {
							node1 = cur_node1 ; 
							node2 = cur_node2 ; 
							continue ; 
						}
						if(cur_node1 < node1) {
							node1 = cur_node1 ; 
							node2 = cur_node2 ; 
						} else if(cur_node1 == node1 && cur_node2 < node2) {
							node2 = cur_node2 ; 
						}
					}
				} 
			} 
		}
		for(auto i : zip[v]) {
			for(auto len : zip[v][i.fi]) zip[u][i.fi].insert(len) ;
		}
	}
}

void solve() {
	if(p == 0 && k == 0) {
		cout << 1 << ' ' << 1 ; 
		exit(0) ;
	}
	dfs(1,1) ;
	node1 = 2e9 , node2 = 2e9 ;
	SML(1,1) ;
	if(node1>node2) {
		swap(node1,node2) ;
	}
	if(node1 == 2e9 && node2 == 2e9) {
		cout << 0 << ' ' << 0 ;
		return ; 
	}
	cout << node1 << ' ' << node2 ;
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