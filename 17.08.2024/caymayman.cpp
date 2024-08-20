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

const int MAXN = 1e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n ; 
vii g[MAXN] ;
int vis[MAXN] ;

bool check(int x) {
	while(x) {
		if(x%10!=4 && x%10!=7) return 0 ;
		x/=10 ;
	}
	return 1 ; 
}

void init() {
	cin >> n ; 
	FOR(i,1,n-1) {
		int u , v , w ; cin >> u >> v >> w ; 
		w = check(w) ; 
		g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
	}
}
int cnt ;
void dfs(int u) {
	vis[u] = 1 ; 
	for(auto [v,w] : g[u]) if(!vis[v] && w==0) {
		cnt++ ; 
		dfs(v) ;	
	}
}

void solve() {
	int ans = 0 ;	
	FOR(i,1,n) if(!vis[i]) {
		cnt = 1 ; 
		dfs(i) ;
		ans+= cnt * (cnt - 1) * (cnt - 2) + cnt * (cnt - 1) * (n - cnt) * 2 ;
	}	
	cout << n * (n - 1) * (n - 2) - ans ;
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