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
const int mod = 1e9 + 7 ;

int n ;
int a[MAXN] ;
int cnt[10 * MAXN],d[10 * MAXN],f[10 * MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) cnt[a[i]]++ ; 
}

int LT(int x,int y) {
	if(y==0) return 1 ; 
	if(y==1) return x ; 
	int c = LT(x,y/2) % mod ;
	if(y&1) return 1LL * c * c % mod * x % mod ; 
	else return 1LL * c * c % mod ;
}

void solve() {
	int mx = *max_element(a+1,a+1+n) ; 
	FOR(i,1,mx) {
		for(int j = i ; j <= mx ; j+=i) d[i]+= cnt[j] ;
	}
	FORD(i,mx,1) {
		f[i] = LT(2,d[i]) - 1 ; 
		for(int j = 2 * i ; j <= mx ; j+=i) f[i] = (f[i] - f[j] + mod) % mod ; 
	}
	int ans = 0 ;
	FOR(i,1,mx) ans = (ans + 1LL * i * f[i] % mod) % mod ;
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