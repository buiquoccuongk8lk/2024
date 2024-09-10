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

const int MAXN = 3e5 + 5 ;

int n ; 
ll k ;
ll a[MAXN],pre[MAXN] ;

void init() {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] , pre[i] = pre[i-1] + a[i] ;
}

ll st[4*MAXN][3] ;

void up(int pos,int val,int t) {
	int id = 1 , l = 1 , r = n ; 
	while(l < r) {
		int mid = (l+r)/2 ; 
		if(pos <= mid) id = id << 1 , r = mid ;
		else id = id << 1 | 1 , l = mid + 1 ; 
	}
	st[id][t] = val ; 
	while(id > 1) {
		id>>=1 ; 
		st[id][t] = max(st[id<<1][t],st[id<<1|1][t]) ;
	}
}

int WalkL(int id,int l,int r,int u,int v,int val) {
	if(l > v || r < u || st[id][1] < val) return -1 ; 
	if(l==r) return l ; 
	int mid = (l+r)/2 ; 
	int ret = WalkL(id<<1|1,mid+1,r,u,v,val) ;
	if(ret==-1) ret = WalkL(id<<1,l,mid,u,v,val) ; 
	return ret ; 
}

int WalkR(int id,int l,int r,int u,int v,int val) {
	if(l > v || r < u || st[id][2] < val) return -1 ; 
	if(l==r) return l ; 
	int mid = (l+r)/2 ; 
	int ret = WalkR(id<<1,l,mid,u,v,val) ; 
	if(ret==-1) ret =  WalkR(id<<1|1,mid+1,r,u,v,val) ;
	return ret ; 
}

bool check(ll mid) {
	FOR(i,1,n) {
		int l = WalkL(1,1,n,1,i-1,mid-i) ;
		int r = WalkR(1,1,n,i+1,n,mid+i) ;
		if(l==-1 || r==-1) continue ;
		l++ ; r-- ;
		ll cnt = pre[r] - pre[l-1] - 1ll *(r-l+1)*mid + 1ll * (i-l)*(i-l+1)/2 + 1ll * (r-i)*(r-i+1)/2 ;
		cnt = abs(cnt) ;
		if(cnt <= k) return 1 ;
	}
	return 0 ;
}

void solve() {
	FOR(i,1,n) {
		up(i,a[i]-i,1) ;
		up(i,a[i]+i,2) ;
	}
	ll ans = -1 ;\
	FOR(i,1,n) maxi(ans,a[i]) ;
	ll l = ans , r = 2e18 ;
	while(l <= r) {
		ll mid = (l+r)>>1 ; 
		if(check(mid)) ans = mid , l = mid + 1 ; 
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
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */