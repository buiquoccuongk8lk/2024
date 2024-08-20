#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN 200005

int n , m ; 
int c[MAXN] ; 
vi g[MAXN] ; 
ii e[MAXN] ; 
unordered_map<int,int> cnt[MAXN] ;
int par[MAXN] ;

void init() {
	cin >> n >> m ; 
	FOR(i,1,n) cin >> c[i] ; 
	FOR(i,1,m) cin >> e[i].fi >> e[i].se ;  
}

int acs(int u) {
	if(u==par[u]) return u ; 
	else return par[u] = acs(par[u]) ;
}

int ans = 0 ; 

bool join(int u,int v) {
	int x = acs(u) , y = acs(v) ; 
	if(x==y) return 0 ; 
	if(g[x].size()>g[y].size())swap(x,y) ; 
	par[x] = y ;
	for(auto i : g[x]) ans+= cnt[y][c[i]] , g[y].pb(i) ; 
	for(auto i : g[x]) cnt[y][c[i]]++ ; 
	return 1 ; 
}

void solve() {
	FOR(i,1,n) {
		par[i] = i ; 
		cnt[i][c[i]] = 1 ;
		g[i].pb(i) ; 
	}
	FOR(i,1,m) {
		join(e[i].fi,e[i].se) ; 
		cout << ans << '\n' ;
	}
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