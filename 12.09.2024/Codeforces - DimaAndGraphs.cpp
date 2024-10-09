// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 3e3 + 3 ;

int n , m ;
struct Edges {
	int u , v , l , r ; 
	bool operator <(const Edges &x) const {
		return l < x.l ; 
	}
} e[MAXN] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,m) cin >> e[i].u >> e[i].v >> e[i].l >> e[i].r ; 
}


int par[MAXN] ;

void init_DSU(void) {
	for(int i(1) ; i <= n ; i++) par[i] = i ;
}

int acs(int u){
	if(par[u]==u) return u ; 
	return par[u] = acs(par[u]) ; 
}

bool join(int u,int v) {
	int x = acs(u) ; 
	int y = acs(v) ;
	if(x==y) return 0 ; 
	par[y] = x ; 
	return 1 ; 
}

void solve() {
	sort(e+1,e+1+m) ; 
	int ans = 0 ; 
	FOR(i,1,m) {
		init_DSU() ; 
		FOR(j,1,m) if(e[j].r >= e[i].r) {
			join(e[j].u,e[j].v) ; 
			if(acs(1)==acs(n)) maxi(ans,e[i].r - e[j].l + 1) ; 
		}
	}
	if(ans==0) cout << "Nice work, Dima!" ;
	else cout << ans ; 
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