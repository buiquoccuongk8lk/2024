// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
// #define int long long
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
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a) 

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 2e5 + 5 ; 
const ll inf = 1e18 ;

int n ; 
ll a[MAXN] ;
ll f[MAXN] , s[MAXN] ;
ll deCompress[MAXN],VAL ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,n) {
		s[i] = s[i-1] + a[i] ; 
		f[i] = f[i-1] + 1ll * i * a[i] ; 
	}
}

vector<ll> V ; 
void Compress() {
	FOR(i,0,n) V.pb(s[i]) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ;
	FOR(i,0,V.size()-1) deCompress[i+1] = V[i] ; 
	VAL = V.size() ;
}

struct line {
	ll a , b ; 
	line() {
		a = 0 ; 
		b = -inf ; 
	}
	line(ll _a,ll _b) {
		a = _a ; 
		b = _b ; 
	}
	ll operator () (ll x ) {
		return 1ll * a * x + b ; 
	}
} ; 

struct LichaoTree {
	line st[4*MAXN] ; 

	void up(int id,int l,int r,line L) {
		if(l==r) {
			if(st[id](deCompress[l]) < L(deCompress[l]))swap(st[id],L) ;
			return ; 
		}
		int mid = (l+r)>>1 ; 
		if(st[id].a>L.a)swap(st[id],L) ; 
		if(st[id](deCompress[mid]) < L(deCompress[mid])) {
			swap(st[id],L) ; 
			up(id<<1,l,mid,L) ; 
		} else up(id<<1|1,mid+1,r,L) ; 
	}

	ll get(int id,int l,int r,ll x) {
		if(l==r) return st[id](deCompress[l]) ; 
		int mid = (l+r)>>1 ; 
		if(x<=mid)return max(st[id](deCompress[x]),get(id<<1,l,mid,x)) ; 
		else return max(st[id](deCompress[x]),get(id<<1|1,mid+1,r,x)) ; 
	}
} lct ; 

void solve() {
	Compress() ; 
	ll ans = 0 ; 
	int l = -1 , r = -1 ; 
	FOR(i,0,n) {
		int pos = lower_bound(all(V),s[i]) - V.begin() + 1 ; 
		ll sum = f[i] + lct.get(1,1,VAL,pos) ; 
		if(maxi(ans,sum)) r = i ; 
		lct.up(1,1,VAL,line(-i,1ll*i*s[i]-f[i])) ; 
	}
	cout << ans << '\n' ; 
	for(l = r ; l >= 1 ; l--) {
		ll sum = 1ll * (f[r] - f[l-1]) - 1ll * (l-1) * (s[r] - s[l-1]) ; 
		if(sum == ans) break ; 
	}
	cout << l << ' ' << r ;
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