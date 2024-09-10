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

const int MAXN = 1e5 + 5 ;

int n , mod ;
ll a[MAXN] ;

void init() {
	cin >> n >> mod ; 
	FOR(i,1,n) cin >> a[i] ;
	sort(a+1,a+1+n) ;
}

void add(ll &a,ll b) { a += b; a -= (a >= mod ? mod : 0); }

ll mul(ll a,ll b) {
    a %= mod , b %= mod ;
    if (b == 0) return 0;
    ll ret = a;
    --b;
    while(b) {
        if (b & 1) add(ret, a); 
        add(a, a);
        b >>= 1;
    }
    return ret;
}

void solve() {
	ll ans = 1 ; 
	FOR(i,1,n) {
		if(a[i] - (i-1) <= 0) {
			cout << 0 ; 
			return ;
		}
		ans = mul(ans,1ll * (a[i] - (i-1))) ;
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