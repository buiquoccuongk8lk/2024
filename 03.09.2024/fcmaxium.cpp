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

int n , q ;
int a[MAXN] ;
struct Queries {
	int l , r , val , id ; 
} Q[MAXN] ;
int sqrtN , l , r ;
int ans[MAXN] ;

void init() {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ; 
	//FOR(i,1,q) cin >> Q[i].l >> Q[i].r >> Q[i].val , Q[i].id = i ;
}

void solve() {
	while(q--) {
		int l , r , val ;
		cin >> l >> r >> val ; 
		int id = lower_bound(a+l,a+1+r,val) - a ;
		if(id==r+1) cout << - 1 ; 
		else cout << a[id] ;
		cout << '\n' ;
	}
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