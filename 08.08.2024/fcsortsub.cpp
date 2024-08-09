#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define int long long
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 200005

int n , q , k ; 
int a[MAXN] ; 
struct Queries {
	int L , R ; 
} Q[MAXN] ; 

void init() {
	cin >> n >> q >> k ; ++k ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,q) {
		cin >> Q[i].L >> Q[i].R ; 
		Q[i].L++ , Q[i].R++ ; 
	}
}

struct SegmentTree {
	int st[4*MAXN] , lazy[4*MAXN] ; 
	void reset() {FOR(i,1,4*n) st[i] = 0 , lazy[i] = - 1 ; }
	void build(int id,int l,int r,int val) {
		if(l==r) {
			st[id] = (a[l] < val ? 0 : 1) ;
			return ; 
		}
		int mid = (l+r)/2 ; 
		build(id<<1,l,mid,val) ; 
		build(id<<1|1,mid+1,r,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ; 
	}
	void down(int id,int l,int r) {
		if(lazy[id]==-1) return ; 
		int mid = (l+r)/2 ; 

		st[id<<1] = (mid - l + 1) * lazy[id] ; 
		st[id<<1|1] = (r - mid) * lazy[id] ; 

		lazy[id<<1] = lazy[id] ; 
		lazy[id<<1|1] = lazy[id] ; 

		lazy[id] = -1 ; 
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return ; 
		if(l >= u && r <= v) {
			st[id] = (r - l + 1) * val ; 
			lazy[id] = val ; 
			return ; 
		}
		down(id,l,r) ;
		int mid = (l+r)/2 ; 
		update(id<<1,l,mid,u,v,val) ; 
		update(id<<1|1,mid+1,r,u,v,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ; 
	}
	int get(int id,int l,int r,int u,int v) {
		if(l > v || r < u) return 0 ;
		if(l >= u && r <= v) return st[id] ; 
		down(id,l,r) ; 
		int mid = (l+r)/2 ; 
		return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
	}
} st ; 

bool check(int mid) {
	st.reset() ; 
	st.build(1,1,n,mid) ; 
	FOR(i,1,q) {
		int l = Q[i].L , r = Q[i].R ; 
		int cnt = r - l + 1 - st.get(1,1,n,l,r) ; 
		st.update(1,1,n,l,l+cnt-1,0) ; 
		st.update(1,1,n,l+cnt,r,1) ; 
	}
	return st.get(1,1,n,k,k) ; 
}

void solve() {
	vector<int> val ; 
	FOR(i,1,n) val.push_back(a[i]) ; 
	sort(val.begin(),val.end()) ; 
	int l = 0 , r = val.size() - 1 , ans = 0 ; 
	while(l <= r) {
		int mid = (l+r)/2 ; 
		if(check(val[mid])) ans = val[mid] , l = mid + 1 ; 
		else r = mid - 1 ; 
	}
	cout << ans ; 
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