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

const int MAXN = 1e5 + 5 ;

int n , q ;
int a[MAXN],L[MAXN],R[MAXN] ;
struct Queries {
	int p,x,id ;
} Q[MAXN] ;
int ans[MAXN] ;
ii curDown[MAXN],curUp[MAXN] ;

void init() {
	cin >> n >> q ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,q) cin >> Q[i].p >> Q[i].x , Q[i].id = i ; 
}

void Compress() {
	vi V ; 
	FOR(i,1,q) V.pb(Q[i].x) ;
	FOR(i,1,n) V.pb(a[i]) ; 
	sort(all(V)) ; 
	V.resize(unique(all(V))-V.begin()) ;
	FOR(i,1,n) a[i] = lower_bound(all(V),a[i]) - V.begin() + 1 ;
	FOR(i,1,q) Q[i].x = lower_bound(all(V),Q[i].x) - V.begin() + 1 ;
}

struct SegmentTree {
	int st[4*MAXN][3] ; 
	void up(int pos,int val,int t) {
		int id = 1 , l = 1 , r = n ; 
		while(l < r) {
			int mid = (l+r)/2 ; 
			if(pos <= mid) id = id << 1 , r = mid ;
			else id = id << 1 | 1 , l = mid + 1 ; 
		} 
		maxi(st[id][t],val) ;
		while(id > 1) {
			id = id >> 1 ; 
			st[id][t] = max(st[id<<1][t],st[id<<1|1][t]) ; 
		}
	}
	int get(int id,int l,int r,int u,int v,int t) {
		if(l>v||r<u)return 0 ;
		if(l>=u&&r<=v)return st[id][t] ;
		int mid = (l+r)>>1 ; 
		return max(get(id<<1,l,mid,u,v,t),get(id<<1|1,mid+1,r,u,v,t)) ; 
	}
	void reset() {
		FOR(i,1,4*n)FOR(t,1,2) st[i][t] = 0 ;
	}
} st ;

void build_LIS() {
	FOR(i,1,n) {
		L[i] = st.get(1,1,n,1,a[i]-1,1) + 1 ; 
		st.up(a[i],L[i],1) ; 
	}
	FORD(i,n,1) {
		R[i] = st.get(1,1,n,a[i]+1,n,2) + 1 ; 
		st.up(a[i],R[i],2) ;
	}
}

void solve() {
	Compress() ;
	build_LIS() ;

	FOR(i,1,n) curDown[i] = curUp[i] = {a[i] , i} ; 

	sort(curDown+1,curDown+1+n) ; 
	
	sort(curUp+1,curUp+1+n,greater<ii>()) ;

	sort(Q+1,Q+1+q,[](Queries u,Queries v) {
		return u.x < v.x ; 
	}) ;

	st.reset() ;

	int lD = 1 , lR = n ; 

	FOR(i,1,q) {
		int val = Q[i].x ;
		while(lD <= n && curDown[lD].fi < val) {
			st.up(curDown[lD].se,L[curDown[lD].se],1) ; 
			lD++ ;
		}
		while(lR >= 1 && curUp[lR].fi > val) {
			st.up(curUp[lR].se,R[curUp[lR].se],2) ;
			lR-- ;
		}
		maxi(ans[Q[i].id],st.get(1,1,n,1,Q[i].p-1,1)+st.get(1,1,n,Q[i].p+1,n,2)+1) ; 
	}

	FOR(i,1,q) cout << ans[i] << '\n' ;
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