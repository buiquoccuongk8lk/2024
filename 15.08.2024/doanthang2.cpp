#include <bits/stdc++.h>
#define int long long
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
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ; 
#define MAXN 1000005

int n , m ;
struct DL {
	int l , r , w ; 
} a[MAXN] ;
int dp[MAXN] ;
vii seg[MAXN] ;

struct SegmentTree {
	int st[4*MAXN] ;
	void update(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return ; 
		if(l >= u && r <= v) {
			st[id] = val ; 
			return ; 
		}
		int mid = (l+r)/2 ; 
		update(id<<1,l,mid,u,v,val) ; 
		update(id<<1|1,mid+1,r,u,v,val) ; 
		st[id] = min(st[id<<1],st[id<<1|1]) ; 
	}
	int get(int id,int l,int r,int u,int v) {
		if(l > v || r < u) return 1e18 ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)/2 ; 
		return min( get(id<<1,l,mid,u,v) , get(id<<1|1,mid+1,r,u,v) ) ; 
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
    	cin >> a[i].l >> a[i].r >> a[i].w ;
    	seg[a[i].r].pb(ii(a[i].l,a[i].w)) ;
    }	
    FOR(i,1,n) {
    	dp[i] = 1e18 ;
    	for(auto x : seg[i]) {
    		int L = x.fi - 1 ;
    		int R = i ; 
    		int w = x.se ; 
    		mini(dp[i],st.get(1,0,n,L,R-1) + w) ;
    	}
    	st.update(1,0,n,i,i,dp[i]) ; 
   	}
   	cout << (dp[n] >= 1e18 ? -1 : dp[n]) ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}