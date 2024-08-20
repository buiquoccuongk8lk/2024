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

int n , root ;
vi g[MAXN] ;
int f[MAXN] ;

void dfs(int u,int par) {
	vi ans ;
	for(auto v : g[u]) {
		if(v==par) continue ; 
		dfs(v,u) ;
		ans.pb(f[v]) ; 
	}
	sort(all(ans)) ; 
	reverse(all(ans)) ;
	FOR(s,0,ans.size()-1) maxi(f[u],ans[s] + s + 1) ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> root ;
    FOR(i,1,n-1) {
    	int u , v ; cin >> u >> v ; 
    	g[u].pb(v) ; g[v].pb(u) ; 
    }
    dfs(root,root) ;
    cout << f[root] ;  
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}