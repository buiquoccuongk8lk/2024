/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;
#define int long long

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
ii x[N] , y[N] , z[N] ; 
struct edge {
	int u ;
	int v ; 
	int w ; 
	bool operator <(const edge &e) const {
		return w < e.w ;
	}
}; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) {
		cin >> x[i].fi >> y[i].fi >> z[i].fi ;
		x[i].se = y[i].se = z[i].se = i ;
	}
}

int par[N] ;

void init_DSU(void) {
	for(int i(1) ; i <= n ; i++) par[i] = i ;
}

int acs(int u){
	if(par[u]==u) return u ; 
	return par[u] = acs(par[u]) ; 
}

void joint(int u,int v) {
	int x = acs(u) ; 
	int y = acs(v) ;
	if(x!=y) {
		par[x] = y ;
	}
}

void process(void) {
	ll ans = 0 ; 
	vector<edge> vec ; 
	sort(x+1,x+1+n) ;
	sort(y+1,y+1+n) ;
	sort(z+1,z+1+n) ;
	FOR(i,2,n) {
		vec.pb({ x[i].se , x[i-1].se , abs(x[i].fi - x[i-1].fi) }) ; 
		vec.pb({ y[i].se , y[i-1].se , abs(y[i].fi - y[i-1].fi) }) ; 
		vec.pb({ z[i].se , z[i-1].se , abs(z[i].fi - z[i-1].fi) }) ; 
 	}
 	sort(all(vec)); 
 	init_DSU() ;
 	for(auto x : vec) {
 		int u = x.u ; 
 		int v = x.v ; 
 		int w = x.w ; 
 		if(acs(u)!=acs(v)) {
 			joint(u,v) ; 
 			ans+= w ; 
 		}
 	}
 	cout << ans ;
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
    return (0 ^ 0) ; 
}