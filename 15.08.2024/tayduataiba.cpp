#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN 200005 

int n , m , q ; 
struct Queries {
	int u , v , w , id ; 
	bool operator <(const Queries &x) const {
		return w < x.w ; 
	}
} Q[MAXN] ;
struct Edges {
	int u  , v , w , id ;
	bool operator <(const Edges &x) const {
		return w < x.w ;
	}
} e[MAXN] ;
int h[MAXN] , ans[MAXN] ;

void init() {
	cin >> n >> m ;
	FOR(i,1,n) cin >> h[i] ; 
	FOR(i,1,m) {
		int u , v ; cin >> u >> v ; 
		e[i] = {u , v , max(h[u],h[v]) , i} ; 
	}
	cin >> q ; 
	FOR(i,1,q) {
		cin >> Q[i].u >> Q[i].v >> Q[i].w ; 
		Q[i].w+= h[Q[i].u] ;
		Q[i].id = i ; 
	}
}

int par[MAXN] ; 
int acs(int u) { 
	if(par[u]==u) return u ; 
	else return par[u] = acs(par[u]) ; 
}
bool join(int u,int v) {
	int x = acs(u) , y = acs(v) ;
	if(x==y) return 0 ; 
	par[y] = x ; 
	return 1 ; 
}

void solve() {
	FOR(i,1,n)par[i] = i ;
	sort(e+1,e+1+m) ; 
	sort(Q+1,Q+1+q) ; 
	int j = 0 ; 
	FOR(i,1,q) {
		auto [u,v,w,id] = Q[i] ; 
		while(j <= m && e[j].w <= w) {
			join(e[j].u,e[j].v) ; 
			j++ ;
		}
		if(acs(u)==acs(v)) ans[id] = 1 ; 
	}
	FOR(i,1,q) cout << (ans[i] ? "YES" : "NO") << endl ;
} 

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}