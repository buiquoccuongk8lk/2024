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

const int MAXN = 1e6 + 5 ;
const ll inf = 1e18 ;

int n ; 
struct DL {
	ll x,y,c ; 
} a[MAXN] ;
int deCompress[MAXN],VAL ;
ll dp[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].x >> a[i].y >> a[i].c ; 
	sort(a+1,a+1+n,[](DL u,DL v) {
		return u.x < v.x ; 
	}) ; 
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
	ll operator () (ll x) {
		return a * x + b ; 
	}
} ; 

struct LichaoTree {
	line st[4*MAXN] ;

	void up(int id,int l,int r,line L) {
		if(l==r) {
			if(st[id](deCompress[l])<L(deCompress[l])) swap(st[id],L) ; 
			return ;  
		}
		int mid = (l+r)>>1 ;
		if(st[id].a>L.a)swap(st[id],L) ; 
		if(st[id](deCompress[mid]) < L(deCompress[mid])) {
			swap(st[id],L) ; 
			up(id<<1,l,mid,L) ; 
		} else up(id<<1|1,mid+1,r,L) ;
	}

	ll get(int id,int l,int r,int x) {
		if(l==r) return st[id](deCompress[l]) ; 
		int mid = (l+r)>>1 ; 
		if(x<=mid) return max(st[id](deCompress[x]),get(id<<1,l,mid,x)) ; 
		else return max(st[id](deCompress[x]),get(id<<1|1,mid+1,r,x)) ; 
	}
} lct ;

vi V ;
void Compress() {
	FOR(i,1,n) V.pb(a[i].y) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ; 
	FOR(i,0,V.size()-1) deCompress[i+1] = V[i] ;
	VAL = V.size() ;
} 

void solve() {
	Compress() ;
	ll ans = 0 ;
	FOR(i,1,n) {
		ll x = a[i].x ; 
		ll y = a[i].y ; 
		ll c = a[i].c ; 
		int p = lower_bound(all(V),y) - V.begin() + 1 ;
		dp[i] = x * y - c + max(1ll*0,lct.get(1,1,VAL,p)) ; 
		lct.up(1,1,VAL,line(-x,dp[i])) ;
		maxi(ans,dp[i]) ; 
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