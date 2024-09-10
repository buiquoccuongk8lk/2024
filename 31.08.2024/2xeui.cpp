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

int n , X ; 
vii g[MAXN] ;
int total = 0 ; 

void init() {
	cin >> n >> X ; 
	FOR(i,1,n-1) {
		int u,v,w ; cin>>u>>v>>w ;
		g[u].pb(ii(v,w)) ; g[v].pb(ii(u,w)) ; 
		total+= w ;
	}
}

int h[MAXN] ;
void dfs(int u,int par) {
	for(auto x : g[u]) {
		if(x.fi==par)continue ;
		h[x.fi] = h[u] + x.se ; 
		dfs(x.fi,u) ;
	}
}

void solve() {
	dfs(1,1) ; 
	int root1 = -1 , ma = 0 ; 
	FOR(i,1,n)if(maxi(ma,h[i]))root1 = i ;
	memset(h,0,sizeof h) ; 
	dfs(root1,root1) ; 
	int root2 = -1 ; ma = 0 ; 
	FOR(i,1,n)if(maxi(ma,h[i]))root2 = i ;
	cout << 2 * total - h[root2] ;
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