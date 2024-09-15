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

int n ; 
ll a[MAXN] , dp[MAXN] , deCompress[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void Compress() {
	vector<ll> V ; 
	FOR(i,1,n) V.pb(a[i]) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ; 
	FOR(i,1,n) {
		int p = lower_bound(all(V),a[i]) - V.begin() + 1 ; 
		deCompress[p] = a[i] ; 
		a[i] = p ;
	}
}

ll st[4*MAXN] ; 
void up(int pos,ll val) {
	int l = 1 , r = n , id = 1 ; 
	while(l < r) {
		int mid = (l+r)>>1 ; 
		if(pos <= mid) id = id << 1 , r = mid ; 
		else id = id << 1 | 1 ,l = mid + 1 ; 
	}
	maxi(st[id],val) ; 
	while(id > 1) {
		id>>= 1 ; 
		st[id] = max(st[id<<1],st[id<<1|1]) ; 
	}
}
ll get(int id,int l,int r,int u,int v) {
	if(l > v || r < u) return -0 ; 
	if(l >= u && r <= v) return st[id] ; 
	int mid = (l+r)>>1 ; 
	return max(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v)) ; 
}

void solve() {
	Compress() ; 
	FOR(i,1,n) {
		dp[i] = get(1,1,n,1,a[i]-1) + deCompress[a[i]] ; 
		up(a[i],dp[i]) ; 
	}
	cout << *max_element(dp+1,dp+1+n) ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ; 
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 