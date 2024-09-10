// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
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
const int MAXN = 1e6 + 5 ;
const int mod = 1e9 + 7 ;

int n ;
int cnt[MAXN] ;
int mx ;
int f[MAXN] ;
int d[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) {
		int x ; cin >> x ; cnt[x]++ ;
		maxi(mx,x) ;
	}
}

int LT(int x,int y) {
	if(y==0) return 1 ; 
	if(y==1) return x ; 
	int c = LT(x,y/2) ; 
	if(y&1) return 1ll * c * c % mod * x % mod ;
	else return 1ll * c * c % mod ;
}

void solve() {
	FOR(i,2,mx) {
		for(int j = i ; j <= mx ; j+=i) d[i]+= cnt[j] ;
	}
	int ans = 0;
	FORD(i,mx,2) {
		f[i] = 1ll * d[i] * LT(2,d[i]-1) % mod ;
		for(int j = 2 * i ; j <= mx ; j+=i) {
			f[i] = (f[i] - f[j] + mod) % mod ; 
		}
		ans = (ans + i * f[i] % mod) % mod ; 
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