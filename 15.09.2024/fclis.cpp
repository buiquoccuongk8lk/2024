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

const int MAXN = 2e6 + 5 ;

int n ; 
ii a[MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i].fi >> a[i].se ; 
}

namespace subtask_1 {
	bool check() {
		FOR(i,2,n) if(a[i].fi != a[i-1].fi + a[i-1].se) return 0 ;
		return 1 ; 
	}
	void solve() {
		int ans = 0 ; 
		FOR(i,1,n) ans+=a[i].se ;
		cout<< ans ; 
	}
}

namespace subtask_23 {
	ll b[MAXN] , deCompress[MAXN] ;
	int sz ;
	bool check() {
		FOR(i,1,n) {
			int x = a[i].fi , y = a[i].fi + a[i].se - 1 ; 
			FOR(j,x,y) b[++sz] = j ; 
			if(sz > 1e6) return 0 ; 
		}
		return 1 ; 
	}
	int dp[MAXN] ;
	void Compress() {
		vector<ll> V ; 
		FOR(i,1,sz) V.pb(b[i]) ; 
		sort(all(V)) ; 
		V.resize(unique(all(V))-V.begin()) ; 
		FOR(i,1,sz) {
			int p = lower_bound(all(V),b[i]) - V.begin() + 1 ; 
			deCompress[p] = b[i] ; 
			b[i] = p ;
		}
	}

	ll st[4*MAXN] ; 
	void up(int pos,ll val) {
		int l = 1 , r = sz , id = 1 ; 
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
		if(l > v || r < u) return 0 ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)>>1 ; 
		return max(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v)) ; 
	}
	void solve() {
		sz = 0 ; 
		FOR(i,1,n) {
			int x = a[i].fi , y = a[i].fi + a[i].se - 1 ; 
			FOR(j,x,y) b[++sz] = j ; 
		}
		Compress() ;
		FOR(i,1,sz) {
			dp[i] = get(1,1,sz,1,b[i]-1) + 1 ; 
			up(b[i],dp[i]) ; 
		}
		cout << *max_element(dp+1,dp+1+sz) ;
	}
}

namespace subtask_4 {
	ll dp[MAXN] ;	
	unordered_map<ll,ll> pos ;
	int VAL ;

	void Compress() {
		vector<ll> V ; 
		FOR(i,1,n) V.pb(a[i].fi) , V.pb(a[i].se) ; 
		sort(all(V)) ; 
		V.resize(unique(all(V))-V.begin()) ; 
		FOR(i,0,V.size()-1) pos[V[i]] = i + 1 ;
		VAL = V.size() ; 
	}

	ll st1[4*MAXN],st2[4*MAXN] ; 

	void up(int pos,ll val,ll st[]) {
		int l = 1 , r = VAL , id = 1 ; 
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

	ll get(int id,int l,int r,int u,int v,ll st[]) {
		if(l > v || r < u) return -1e18 ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)>>1 ; 
		return max(get(id<<1,l,mid,u,v,st),get(id<<1|1,mid+1,r,u,v,st)) ; 
	}

	void solve() {
		FOR(i,1,n) a[i].se = a[i].fi + a[i].se - 1; 
		Compress() ;
		FOR(i,1,4*VAL) st1[i] = -1e18 , st2[i] = -1e18 ; 

		FOR(i,1,n) {
			dp[i] = a[i].se - a[i].fi + 1 ; 
			maxi(dp[i],get(1,1,VAL,1,pos[a[i].fi]-1,st1) + a[i].se - a[i].fi + 1) ; 
			maxi(dp[i],get(1,1,VAL,pos[a[i].fi],VAL,st2) + a[i].se + 1) ; 
			up(pos[a[i].se],dp[i],st1) ; 
			up(pos[a[i].se],dp[i] - a[i].se - 1 , st2) ; 
		}

		cout << *max_element(dp+1,dp+1+n) ;
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
    /*if(subtask_1::check()) subtask_1::solve() ;
    else if(subtask_23::check()) subtask_23::solve() ; 
    else*/ subtask_4::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 