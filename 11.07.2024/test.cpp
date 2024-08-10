#include <bits/stdc++.h>
using namespace std ; 

#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 5e5 + 5 ;
const int mod_mitsurii = 998244353 ; 

void add(int &x,int val){
	x+= val; 
	if (x >= mod_mitsurii) {
		x -= mod_mitsurii ;
	}
}

ll getval(ll val){
	return (val % mod_mitsurii + mod_mitsurii) % mod_mitsurii;
}

int n,q ; 
vector<int> g[max_mitsurii] ;
int in[max_mitsurii] , out[max_mitsurii] , sum[max_mitsurii] , pos[max_mitsurii] , h[max_mitsurii] ;
int timeDFS ;

void mitsuri_read(void) {
	cin >> n ; 
	FOR(i,2,n) {
		int p ; 
		cin >> p ; 
		g[p].pb(i) ; 
	//	g[i].pb(p) ; 
	}
	cin >> q ; 
}

void dfs(int u,int par) {
	in[u] = ++timeDFS ;
	pos[timeDFS] = u ; 
	for(auto v : g[u]) {
		if(v==par) continue ; 
		h[v] = h[u] + 1 ; 
		dfs(v,u) ; 
	}
	out[u] = timeDFS ; 
}

struct TreeOfMitsuri {

	int st[max_mitsurii*4] , lazy1[max_mitsurii*4] , lazy2[max_mitsurii*4] , lazy3[max_mitsurii*4] , sum[max_mitsurii*4] ; 
	
	void build(int id,int l,int r) {
		if(l==r) { 
			sum[id] = h[pos[l]] ;
			return ; 
		}
		int mid = (l+r)>>1 ; 
		build(id<<1,l,mid) ; 
		build(id<<1|1,mid+1,r) ;
		sum[id] = sum[id<<1] + sum[id<<1|1] ; 
		if(sum[id]>=mod_mitsurii) sum[id]-=mod_mitsurii ;
	}

	void down(int id,int l,int r) {

		if(lazy1[id]==0 and lazy2[id]==0 and lazy3[id]==0) return ; 
		int mid = (l+r)>>1 ; 

		add( st[id<<1] , (1ll*(mid-l+1)*lazy1[id] + 1ll*sum[id<<1]*lazy2[id]) %mod_mitsurii ) ; 
	
		add( st[id<<1|1] , (1ll*(r-mid)*lazy1[id] + 1ll*sum[id<<1|1]*lazy2[id]) %mod_mitsurii )  ; 

		add(lazy1[id<<1],lazy1[id]) ; 
		add(lazy1[id<<1|1],lazy1[id]) ; 

		add(lazy2[id<<1],lazy2[id]) ; 
		add(lazy2[id<<1|1],lazy2[id]) ; 

		lazy1[id] = lazy2[id] = 0 ;
	}

	void update(int id,int l,int r,int u,int v,int val1,int val2) {
		if(l > v or r < u) return ; 
		if(l >= u and r <= v) {
			add(st[id], (1ll*(r-l+1)*val1 + 1ll*sum[id]*val2)%mod_mitsurii ) ; 
			add(lazy1[id],val1) ; 
			add(lazy2[id],val2) ; 
			return ; 
		}
		down(id,l,r) ; 
		int mid = (l+r)>>1 ; 
		update(id<<1,l,mid,u,v,val1,val2) ; 
		update(id<<1|1,mid+1,r,u,v,val1,val2) ; 
		st[id] = (st[id<<1] + st[id<<1|1]) ; 
		if(st[id]>=mod_mitsurii) st[id]-=mod_mitsurii ; 
	}

	int get(int id,int l,int r,int u,int v) {
 		if(l > v or r < u) return 0 ; 
 		if(l >= u and r <= v) return st[id] ; 
 		int mid = (l+r)>>1 ; 
 		down(id,l,r) ; 
 		int ret =  get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v)  ; 
 		if(ret>=mod_mitsurii) ret-=mod_mitsurii ; 
 		return ret ; 
 	}

} IT ; 

void mitsuri_solve(void) {

	dfs(1,1) ;
	IT.build(1,1,n) ; 
	
	while(q--) {
		string s ; 
		cin >> s ; 
		if(s=="add") {
			int u,k,l ;
			cin >> u >> k >> l ;
			IT.update(1,1,n,in[u],out[u],getval(1LL*k+1LL*l*h[u]), getval(-l)) ; 
		} else if(s=="get") {
			int u ; 
			cin >> u ; 
			cout << IT.get(1,1,n,in[u],in[u]) << ' ' ; 
		} else {
			int u ; 
			cin >> u ; 
			cout << IT.get(1,1,n,in[u],out[u])   << ' ' ;
		}
	}

}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    mitsuri_read() ;
    mitsuri_solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}