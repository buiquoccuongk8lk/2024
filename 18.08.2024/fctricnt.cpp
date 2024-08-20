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
ii a[MAXN] ;
int fact[MAXN] , inv_fact[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ; 
} 

int Pw(int x,int y) {
	if(y==0) return 1 ;
	if(y==1) return x ;
	int c = Pw(x,y/2) ; 
	if(y&1) return c * c % mod * x % mod ; 
	else return c * c % mod ; 
}

int C(int n,int k) {
	return fact[n] * inv_fact[n-k]%mod * inv_fact[k]%mod ;
}

int bit[2*MAXN] ;
int mx ;

void up(int u,int val) {
	for(int i(u) ; i <= 2 * MAXN ; i+=i&-i) bit[i] = (bit[i] + val)%mod ; 
}

int get(int u) {
	int sum = 0 ; 
	for(int i(u) ; i ; i-=i&-i) sum = (sum + bit[i])%mod ; 
	return sum ; 
}

int get(int l,int r) {
	return get(r) - get(l-1) ;
}

void solve() {
	fact[0] = 1 ; 
	FOR(i,1,1e5) fact[i] = (fact[i-1] * i)%mod ; 
	inv_fact[(int)1e5] = Pw(fact[(int)1e5],mod-2) ; 
	FORD(i,1e5-1,1) inv_fact[i] = inv_fact[i+1] * (i+1)%mod ; 
	int ans = 0 ; 
	sort(a+1,a+1+n) ; 
	FOR(i,1,n) ans+= C(a[i].se,3) ;
	FOR(i,1,n) FOR(j,1,n) {
		if(i==j) continue ;
		if(2*a[i].fi > a[j].fi) {
			ans+= C(a[i].se,2) * a[j].se %mod ; 
		}
	}
	FOR(i,1,n) up(a[i].fi,a[i].se) ;
	FOR(i,1,n) {
		FOR(j,i+1,n) {
			ans+= ( get(a[j].fi+1,a[i].fi+a[j].fi-1) * a[i].se%mod * a[j].se ) %mod ;
		}
	}
	cout << ans%mod ; 
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