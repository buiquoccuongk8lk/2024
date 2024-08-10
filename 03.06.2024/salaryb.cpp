/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , q ; 
vi G[N] ; 
int a[N] ; 
void init(void) {
	cin >> n >> q ; 
	cin >> a[1] ; 
	rep(i,2,n) {
		int p ;
		cin >> a[i] >> p ; 
		G[p].pb(i) ; 
		G[i].pb(p) ; 
	}
}	

namespace sub {
	int inp[N] , out[N] ;
	int lazy[8*N] ;  
	int st[8*N] ;
	int sum[N] ;
	int timeDFS = 0 ;
	void dfs(int u,int par) {
		inp[u] = ++timeDFS ; 
		sum[inp[u]] = a[u] ; 
		for(auto v : G[u]) {
			if(v==par) continue ;
			dfs(v,u) ; 
		}
		out[u] = ++timeDFS ; 
	}
	void build(int id,int l,int r) {
		if(l==r) {
			st[id] = sum[l] ; 
			return ; 
		}
		int mid = (l+r)>>1 ;
		build(id<<1,l,mid) ; 
		build(id<<1|1,mid+1,r) ;
	}
	void down(int id,int l,int r) {
		if(lazy[id] == 0) return ; 
		int mid = (l+r)>>1 ; 

		st[id<<1]+= (mid - l + 1) * lazy[id] ; 
		st[id<<1|1]+= (r-mid) * lazy[id] ; 

		lazy[id<<1] += lazy[id] ; 
		lazy[id<<1|1] += lazy[id] ;  

		lazy[id] = 0 ;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if(l > v or r < u) return ;
		if(l >= u and r <= v) {
			st[id]+= (r-l+1) *val ;
			lazy[id]+= val ; 
			return ;  
		}
		down(id,l,r) ; 
		int mid = (l+r)>>1 ; 
		update(id<<1,l,mid,u,v,val) ; 
		update(id<<1|1,mid+1,r,u,v,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ;
	}
	int get(int id,int l,int r,int u,int v) {
		if(l > v or r < u) return 0 ;
		if(l >= u and r <= v) return st[id] ; 
		int mid = (l+r)>>1 ; 
		down(id,l,r) ; 
		return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
	}
    void solve(void) {
    	dfs(1,0) ; 
    	build(1,1,timeDFS) ;
    	while(q--) {
    		char t ;
    		cin >> t ; 
    		if(t == 'p') {
    			int u , x ;
    			cin >> u >> x ; 
    			update(1,1,timeDFS,inp[u] + 1,out[u],x) ; 
    		}else {
    			int u ; 
    			cin >> u ;
    			cout << get(1,1,timeDFS,inp[u],inp[u]) << '\n' ; 
    		}
    	}
    }
    
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    sub::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}