#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)
template<class X,class Y> bool maxi(X &x,const Y &y) {if(x < y){x = y ; return 1;}else return 0;}
template<class X,class Y> bool mini(X &x,const Y &y) {if(x > y){x = y ; return 1;}else return 0;}
using namespace std ; 
#define MAXN 200005

int n , m ;
vii add[MAXN] , del[MAXN] ; 
int dp[MAXN] ;

struct SegmentTree {
	int st[4*MAXN] , lazy[4*MAXN] ; 
	void init() {
		FOR(i,1,4*n) st[i] = -1e18 ;
	}
	void down(int id,int l,int r) {
		if(lazy[id]==0) return ;

		st[id<<1]+= lazy[id] ; 
		st[id<<1|1]+= lazy[id] ; 

		lazy[id<<1]+= lazy[id] ; 
		lazy[id<<1|1]+= lazy[id] ; 

		lazy[id] = 0 ;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return ; 
		if(l >= u && r <= v) {
			st[id]+= val ; 
			lazy[id]+= val ; 
			return ; 
		}
		int mid = (l+r)/2 ; 
		down(id,l,r) ;
		update(id<<1,l,mid,u,v,val) ; 
		update(id<<1|1,mid+1,r,u,v,val) ; 
		st[id] = max(st[id<<1],st[id<<1|1]) ; 
	}
	int get(int id,int l,int r,int u,int v) {
		if(l > v || r < u) return -1e18 ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)/2 ; 
		down(id,l,r) ; 
		return max( get(id<<1,l,mid,u,v) , get(id<<1|1,mid+1,r,u,v) ) ; 
	}
} st ; 

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> m ; 
    FOR(i,1,m) {
    	int l , r , w ; cin >> l >> r >> w ;
    	add[l].pb(ii(r,w)) ; del[r+1].pb(ii(l,w)) ; 
    }
    FOR(i,1,n) {
    	for(auto x : add[i]) st.update(1,0,n,0,i-1,x.se) ;
    	for(auto x : del[i]) st.update(1,0,n,0,x.fi-1,-x.se) ; 
    	dp[i] = st.get(1,0,n,0,i-1) ; 
    	st.update(1,0,n,i,i,dp[i]) ; 
    }
    int ans = -1e18 ; 
    FOR(i,1,n) maxi(ans,dp[i]) ;
    cout << ans ; 
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}