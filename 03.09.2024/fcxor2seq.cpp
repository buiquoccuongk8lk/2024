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

const int MAXN = 2e5 + 5 ;

int n ;
int a[MAXN] , b[MAXN] ;


void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ;
	FOR(i,1,n) cin >> b[i] ;
}

int count (int L,int R) {
	return upper_bound(b+1,b+1+n,R) - lower_bound(b+1,b+1+n,L) - 1 ;
}

void solve() {
	ll ans = 0 ;
	FORD(bit,20,0) {
		int T = 1 << bit ; 
		FOR(i,1,n) a[i]%= 2*T , b[i]%= 2*T ;
		sort(b+1,b+1+n) ;
		int cnt = 0 ;
		FOR(i,1,n) {
			cnt+= count(T-a[i],2*T-1-a[i]) ;
			cnt+= count(3*T-a[i],4*T-1-a[i]) ; 
		}
		if(cnt&1) ans+= T ;
	}
	cout << ans ;
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