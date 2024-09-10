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
const int MAXN = 505 ;

int n ;
struct point {
	ll x , y ;
} a[MAXN] ;
vector<ll> List[2 * MAXN] ;
ll last[2 * MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].x >> a[i].y ;
	FOR(i,1,n) List[a[i].y].pb(a[i].x) ;
}

void solve() {
	ll ans = 0 ; 
	FOR(y,0,1000) if(List[y].size()) {
		for(auto x1 : List[y]) for(auto x2 : List[y]) {
			if(x2 - x1 >= 0) {
				if(!last[x2 - x1]) last[x2 - x1] = y ;
				else maxi(ans,1ll * (y - last[x2 - x1]) * (x2 - x1) ) ; 
			}
		}
	}
	cout << (ans == 0 ? -1 : ans) ;
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