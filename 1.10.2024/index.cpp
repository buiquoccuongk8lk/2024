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

const int N = 2e5 + 5 ;
const int LO = __lg(N) + 1 ;

int n , q ;
int a[N] ; 
vi pos[N] ;

void init() {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ; 
}

struct PersistentSegTree {
	int H[N*LO] ; 
	int L[N*LO],R[N*LO],st[N*LO] ; 
	int node = 0 ;

	int up(int old,int l,int r,int pos,int val) {
		int cur = ++ node ; 
		if(l == r) {
			st[cur] = st[old] + val ; 
			return cur ; 
		}
		int mid = (l+r)>>1 ; 
		if(pos <= mid) {
			R[cur] = R[old] ; 
			L[cur] = up(L[old],l,mid,pos,val) ; 
		} else {
			L[cur] = L[old] ; 
			R[cur] = up(R[old],mid+1,r,pos,val) ; 
		}	
		st[cur] = st[L[cur]] + st[R[cur]] ; 
		return cur ; 
	}

	int get(int id,int l,int r,int u,int v) {
		if(l > v || r < u) return 0 ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)>>1 ; 
		return get(L[id],l,mid,u,v) + get(R[id],mid+1,r,u,v) ; 
	}
} PST ; 

void solve() {
	FOR(i,1,n) pos[a[i]].pb(i) ;
	int mx = *max_element(a+1,a+1+n) ; 
	FORD(i,mx,1) {
		PST.H[i] = PST.H[i+1] ; 
		for(auto v : pos[i]) {
			PST.H[i] = PST.up(PST.H[i],1,n,v,1) ; 
		}
	}	
	while(q--) {
		int L , R ; cin >> L >> R ;
		int l = 1 , r = mx , ans = -1 ; 
		while(l <= r) {
			int mid = (l + r) >> 1 ; 
			if(PST.get(PST.H[mid],1,n,L,R) >= mid) {
				ans = mid ; l = mid + 1 ; 
			} else r = mid - 1 ; 
		}
		cout << ans << endl ;
	}
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
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 