#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

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

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 2e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ;

int n ;
int a[MAXN] , prime[MAXN + 5] ;
vi p[MAXN] ;
bool vis[MAXN] ;
vi g[MAXN] ;
int b[MAXN] ;

void prepare() {
	FOR(i,2,MAXN) prime[i] = i ; 
	FOR(i,2,sqrt(MAXN))
		for(int j = i * i ; j <= MAXN ; j+=i) if(prime[j]==j) prime[j] = i ;
}

void init() {
	prepare() ;
	cin >> n ;
	FOR(i,1,n) {
		cin >> a[i] ; 
		b[i] = a[i] ;
		while(a[i]!=1) {
			p[i].pb(prime[a[i]]) ;
			int tmp = prime[a[i]] ; 
			while(a[i]%tmp==0) {
				a[i]/= tmp ; 
			}
		}
	}
	FOR(i,1,n-1) {
		int u , v ; cin >> u >> v ;
		g[u].pb(v) ; g[v].pb(u) ;
	}
}  

vi V ;
int h[MAXN] , f[MAXN] ;

void dfs(int u,int par,int val) {
	V.pb(u) ; 
	f[u] = h[u] = 1 ;
	for(auto v : g[u]) if(v!=par && b[v]%val==0) {
		dfs(v,u,val) ; 
		f[u] = max({f[u],f[v],h[u] + h[v]}) ;
		h[u] = max(h[u],h[v] + 1) ;
	}	
}	

void solve() {
	int ans = 0 ;	
	FOR(i,1,n) {
		for(auto j : p[i]) {
			for(auto x : V) h[x] = f[x] = 0 ;
			V.clear() ; 
			dfs(i,i,j) ; 	
			ans = max(ans,f[i]) ;
		}
	}
	cout << ans ; 
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