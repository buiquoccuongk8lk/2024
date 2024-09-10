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
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 1e5 + 5 ;

int n ;
int a[MAXN] ;
vi g[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) g[a[i]].pb(i) ;
}

int ans[MAXN] ;

void solve() {
	vi has ;
	FOR(i,1,n) has.pb(a[i]) ; 
	sort(all(has)) ; 
	has.resize(unique(all(has))-has.begin()) ; 
	int cur = n ; 
	for(auto x : has) {
		for(auto id : g[x]) ans[id] = cur-- ; 
	}
	FOR(i,1,n) cout << ans[i] << ' ' ;
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