/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n' 
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)

const int N = 1e5 + 5 ;
const ll inf = 1e18 ;
const int LO = __lg(N) + 1 ;

template <class X,class Y> bool maximize(X &x,const Y &y) {
	if(x < y)  {
		x = y ; 
		return true ; 
	} return false ; 
}


int n , q ;

struct Queries {
	int t , u , v , w ; 
}Q[(int)3e5 + 5] ; 

struct ke {
	int v , w ; 
} ;

vector<ke> G[N] ; 

void init(void) {
	cin >> n >> q ; 
	FOR(i,1,q) {
		int t , u , v , w ; 
		cin >> t ; 
		if(t==1) {
			cin >> u >> v >> w ; 
			Q[i] = {t , u , v , w} ; 
		} else {
			cin >> u ; 
			Q[i] = {t , u , v , w} ; 
		}
	}    
}

int lab[N] , h[N] ;
ll sum[N][LO] ;
int P[N][LO] ; 
pair<int,int> best[N] ;

void dfs(int u,int par) {
	for(auto x : G[u]) {
		int v = x.v ;
		int w = x.w ; 
		if(v==par) continue ; 
		h[v] = h[u] + 1 ; 
		P[v][0] = u ; 
		sum[v][0] = w ;
		dfs(v,u) ; 
	}
}

int lca(int u, int v){
	if (h[u] < h[v]) swap(u, v);

	int z = __lg(h[u]) ; 

	int res = 0;

	FORD(s,z,0) if( (h[u] - h[v] ) >= (1<<s) ) {
		res += sum[u][s]; 
		u = P[u][s];
	}

	if (u == v) return res;

	FORD(s,z,0) if (P[u][s] != P[v][s]) {
		res += sum[u][s] + sum[v][s];
		u = P[u][s]; 
		v = P[v][s];
	}

	return res + sum[u][0] + sum[v][0];
}
int find(int x) {
	return lab[x] < 0 ? x : lab[x] = find(lab[x]) ; 
}

int cur[3][3] ; 

pair<int,int> merge(int x,int y) {

	cur[0][0] = best[x].first ; 
	cur[0][1] = best[x].second ; 
	cur[1][0] = best[y].first ; 
	cur[1][1] = best[y].second ;  

	int maxi = 0 ;
	FOR(u,0,1) FOR(v,0,1) FOR(t1,0,1) FOR(t2,0,1) maxi = max(maxi , lca(cur[u][t1],cur[v][t2]) ) ; 

	FOR(u,0,1) FOR(v,0,1) FOR(t1,0,1) FOR(t2,0,1) if(maxi == lca(cur[u][t1],cur[v][t2])) {
		return {cur[u][t1] , cur[v][t2]} ;
	}
}

bool join(int u,int v,bool ok) {

	int x = find(u) ; int y = find(v) ; 

	if(x==y) return 0 ; 

	if(lab[x] > lab[y]) swap(x,y) ; 

	lab[x]+=lab[y] ; 
	lab[y] = x ; 

	if(ok) best[x] = merge(x , y) ; 

	return 1 ; 
}

void process(void) {

    FOR(i,1,n) {
    	lab[i] = -1 ; 
    	best[i] = {i , i} ; 
    }

    FOR(i,1,q) {
    	if(Q[i].t==1) {
    		if(join(Q[i].u,Q[i].v,0)) {
    			G[Q[i].u].push_back({Q[i].v,Q[i].w}) ; 
    			G[Q[i].v].push_back({Q[i].u,Q[i].w}) ; 
    		}
    	}
    }

    dfs(1,1) ; 

    for(int j(1) ; (1 << j) <= n ; j++) FOR(i,1,n) {
    	int x = P[i][j-1] ; 
    	P[i][j] = P[x][j-1] ; 
    	sum[i][j] = sum[i][j-1] + sum[x][j-1] ; 
    }

    FOR(i,1,n) {
    	lab[i] = -1 ; 
    	best[i] = { i , i } ; 
    }

    FOR(i,1,q) {
    	if(Q[i].t==1) {
    		join(Q[i].u,Q[i].v,1) ; 
    	} else {
    		int u = Q[i].u ; 
    		int cha = find(u) ; 
    		cout << max(lca(u,best[cha].first),lca(u,best[cha].second)) << endl ;
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
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0 ; 
}