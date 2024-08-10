/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;
int n , q ; 
vi G[N] ; 
int a[N] ;
long long st[4*N] , lazy[4*N] ; 
int timeDFS ; 
int inp[N] , out[N] , sum[N] ; 

void build(int id = 1 , int l = 1 , int r = timeDFS ) {
	if(l==r){
		st[id] = sum[l] ; 
		return ; 
	}
	int mid = (l+r) >> 1 ; 
	build(id<<1,l,mid) ; 
	build(id<<1|1,mid+1,r) ; 
	st[id] = st[id<<1] + st[id<<1|1] ;
}
void DFS(int u,int par) {
	inp[u] = ++timeDFS;
	sum[timeDFS] = a[u] ;
	for(auto v : G[u]) {
		if(v==par) continue ;
		DFS(v,u) ; 
	}	
	out[u] = ++timeDFS ; 
}
void down(int id,int l,int r){
	if(lazy[id]==0) return ; 
	int mid = (l+r) >> 1 ; 
	st[id<<1]+= (mid-l+1) * lazy[id] ; 
	st[id<<1|1]+= (r-mid) * lazy[id] ; 

	lazy[id<<1] += lazy[id] ; 
	lazy[id<<1|1] += lazy[id] ;

	lazy[id] = 0 ;
}
void update(int id,int l,int r,int u,int v,long long val)
{
	if(l > v or r < u) return ; 
	if(l >= u and r <= v) {
		st[id]=(r-l+1)*val; 
		lazy[id]=val ;
		return ; 
	}
	down(id,l,r) ;
	int mid = (l+r)>>1;
	update(id<<1,l,mid,u,v,val);
	update(id<<1|1,mid+1,r,u,v,val);
	st[id] = st[id<<1] + st[id<<1|1] ;
}
long long get(int id,int l,int r,int u,int v)
{
	if( l > v or r < u ) return 0;
	if( l >= u and r <= v) return st[id];
	int mid = (l+r)>>1;
	down(id,l,r) ;
	int t1 = get(id<<1,l,mid,u,v);
	int t2 = get(id<<1|1,mid+1,r,u,v);
	return t1 + t2 ;
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ){
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> q ; 
    for(int i(1) ; i <= n ; i++) cin >> a[i] ; 
    for(int i(1) ; i <= n - 1 ; i++) {
    	int u,v ; 
    	cin >> u >> v ; 
    	G[u].push_back(v) ; 
    	G[v].push_back(u) ; 
    }
    DFS(1,0) ; 
    for(int i(1) ; i <= n ; i++) {
    	update(1,1,timeDFS,inp[i],inp[i],a[i]) ; 
    	update(1,1,timeDFS,out[i],out[i],-a[i]) ; 
    }
    for(int i(1) ; i <= n ; i++) {
    	//cout << inp[i] <<" " << out[i]<< endl ;
    }
    while(q--) {
    	int t ; 
    	cin >> t ; 
    	if(t==1) {
    		int u, x ;
    		cin >> u >> x ;
    		update(1,1,timeDFS,inp[u],inp[u],x) ; 
    		update(1,1,timeDFS,out[u],out[u],-x) ; 
    	}else {
    		int u ; 
    		cin >> u  ;
    		cout << get(1,1,timeDFS,inp[1],out[u] - 1) << '\n' ; 
    	}
    }
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}