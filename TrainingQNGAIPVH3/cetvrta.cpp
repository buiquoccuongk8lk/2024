/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;
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
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

ii a[5] ;

void init() {
	cin >> a[1].fi >> a[1].se ; 
	cin >> a[2].fi >> a[2].se ;
	cin >> a[3].fi >> a[3].se ;
}

int cntX[1005] , cntY[1005] ;

void solve() {
	FOR(i,1,3) cntX[a[i].fi]++ ;
	FOR(i,1,3) cntY[a[i].se]++ ; 
	int x = -1 , y = - 1 ; 
	FOR(i,1,3) {
		if(cntX[a[i].fi]==1) x = a[i].fi ;
		if(cntY[a[i].se]==1) y = a[i].se ; 
	}	
	cout << x << ' ' << y ;
}

signed main() {
    #define task "cetvrta"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 