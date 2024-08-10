/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 2e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
vi G[N] ;
ii edge[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n-1) {
		int u,v ; 
		cin >> u >> v ; 
		edge[i].fi = u ;
		edge[i].se = v ; 
		G[u].pb(v) ; G[v].pb(u) ; 
	}
}

namespace sub1 {

	int vis[2005] , h[2005] , del[2005][2005] ;

	void DFS(int u,int par) {
		vis[u] = 1 ;
		h[u] = 1 ;  
		for(auto v : G[u]) {
			if(v==par || vis[v] || del[u][v] || del[v][u]) continue ; 
			DFS(v,u) ; 
			h[u]+=h[v] ;
		}
	}

	void solve(void) {

		int ans = 2e9 ;

		FOR(i,1,n-2) {
			FOR(j,i+1,n-1) {
				del[edge[i].fi][edge[i].se] = 1 ; 
				del[edge[i].se][edge[i].fi] = 1 ;
				del[edge[j].fi][edge[j].se] = 1 ;
				del[edge[j].se][edge[j].fi] = 1 ;   
				FOR(k,1,n) vis[k] = 0 , h[k] = 0 ; 
				int cnt = 0 ;
				multiset<int> ms ;  
				FOR(k,1,n) if(!vis[k]) {
					DFS(k,k) ; 
					cnt++ ; 
					ms.insert(h[k]) ; 
				}
				//cout << cnt << endl ;
				if(cnt==3) {
					//cout << ms.size() << endl ;
					minimize(ans , *ms.rbegin() - *ms.begin() ) ; 
				}
				del[edge[i].fi][edge[i].se] = 0 ; 
				del[edge[i].se][edge[i].fi] = 0 ;
				del[edge[j].fi][edge[j].se] = 0 ;
				del[edge[j].se][edge[j].fi] = 0 ; 
			}
		}

		cout << ans ;
	}

}

namespace sub2 {

	int ChiliOfRoot[N] ;

	void DFS(int u,int par) {
		ChiliOfRoot[u] = 1 ; 
		for(auto v : G[u]) {
			if(v==par) continue ; 
			DFS(v,u) ;
			ChiliOfRoot[u]+=ChiliOfRoot[v] ; 
		}
	}

	// goi Cal(u,par) : gia tri min khi chia nhanh u lam 3 phan

	set<int> P , TP ;

	int calc(int x,int par) {

		int ans = 2e9 ;

		auto val = P.upper_bound( (n+ChiliOfRoot[x]) / 2 ) ; 
		if(val!=P.end()) {
			minimize(ans , max({ChiliOfRoot[x] , *val - ChiliOfRoot[x] , n - *val}) - min({ChiliOfRoot[x] , *val - ChiliOfRoot[x] , n - *val}) ) ; 
		}
		if(val!=P.begin()) {
			--val; 
			minimize(ans , max({ChiliOfRoot[x] , *val - ChiliOfRoot[x] , n - *val}) - min({ChiliOfRoot[x] , *val - ChiliOfRoot[x] , n - *val}) ) ; 
		}

		auto val1 = TP.upper_bound( (n-ChiliOfRoot[x]) / 2 ) ;

		if(val1!=TP.end()) {
			minimize(ans , max({ChiliOfRoot[x] , *val1 , n - ChiliOfRoot[x] - *val1}) -  min({ChiliOfRoot[x] , *val1 , n - ChiliOfRoot[x] - *val1}) ) ;
		}

		if(val1!=TP.begin()) {
			--val1 ; 
			minimize(ans , max({ChiliOfRoot[x] , *val1 , n - ChiliOfRoot[x] - *val1}) -  min({ChiliOfRoot[x] , *val1 , n - ChiliOfRoot[x] - *val1}) ) ;
		}

		P.insert(ChiliOfRoot[x]) ;

		for(auto v : G[x]) {
			if(v==par) continue ;
			minimize(ans , calc(v,x) ) ; 
		}

		P.erase(ChiliOfRoot[x]) ; 
		TP.insert(ChiliOfRoot[x]) ; 

		return ans ;
	}


	void solve(void) {
		DFS(1,1) ; 
		cout << calc(1,0) ; 
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
    /*if(n <= 500) sub1::solve() ;
    else if(n <= 2000)*/ sub2::solve() ;  
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}