#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
#define MAXN 100005

int q , n = 1 , cur = 1 ; 
vector<int> g[MAXN] ; 
struct Queries {
	char t ;
	int u ; 
} Q[MAXN] ; 
int in[MAXN] , out[MAXN] , timeDFS , del[MAXN] ;

void init() {
	cin >> q ; 
	FOR(i,1,q) {
		cin >> Q[i].t >> Q[i].u ; Q[i].u++ ;
		if(Q[i].t=='+') {
			n++ ; 
			g[Q[i].u].push_back(n) ;
		}
	}
}

struct SegmentTree {
	int st[4*MAXN] , lazy[4*MAXN] ; 
	void down(int id,int l,int r) {
		if(lazy[id]==0) return ;
		int mid = (l+r)/2 ; 

		st[id<<1]+= (mid-l+1)*lazy[id] ; 
		st[id<<1|1]+= (r-mid)*lazy[id] ; 

		lazy[id<<1]+= lazy[id] ; 
		lazy[id<<1|1]+= lazy[id] ; 

		lazy[id] = 0 ;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if(l > v || r < u) return ; 
		if(l >= u && r <= v) {
			st[id]+= (r-l+1)*val ; 
			lazy[id]+= val ; 
			return ; 
		}
		int mid = (l+r)/2 ; 
		down(id,l,r) ;
		update(id<<1,l,mid,u,v,val) ; 
		update(id<<1|1,mid+1,r,u,v,val) ; 
		st[id] = st[id<<1] + st[id<<1|1] ; 
	}
	int get(int id,int l,int r,int u,int v) {
		if(l > v || r < u) return 0 ; 
		if(l >= u && r <= v) return st[id] ; 
		int mid = (l+r)/2 ; 
		down(id,l,r) ; 
		return get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v) ; 
	}
} st ; 

void dfs(int u) {
	in[u] = ++timeDFS ; 
	for(auto v : g[u]) {
		dfs(v) ; 
	}
	out[u] = timeDFS ; 
}

void DEL(int u) {
	st.update(1,1,n,in[u],in[u],-1) ; 
	for(auto v : g[u]) {
		if(del[v]) continue ;
		DEL(v) ;
	}
}

void solve() {
	dfs(1) ; 
	st.update(1,1,n,in[cur],in[cur],1) ; 
	FOR(i,1,q) {
		char t = Q[i].t ; int u = Q[i].u ;
		if(t=='+') {
			cur++ ; 
			st.update(1,1,n,in[cur],in[cur],1) ; 
		} else if(t=='-'){
			del[u] = 1 ; 
			DEL(u) ; 
		} else {
			cout << st.get(1,1,n,in[u],out[u]) << '\n' ;
		}
	}
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