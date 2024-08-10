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

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m , k ; 
vi G[N] ;
ll dist[N] ; 
int x[N] ;


void init(void) {
	cin >> n >> k >> m ;
	FOR(i,1,m) {
		FOR(j,1,k) {
			cin >> x[j] ; 
			G[x[j]].pb(n+i) ; 
			G[n+i].pb(x[j]) ; 
		}
	}
}

void process(void) {
	FOR(i,2,n+m) dist[i] = inf ; 
	deque<int>dq ;
	dist[1] = 1 ;  
	dq.pb(1) ; 
    while(!dq.empty()) {
    	int u = dq.front() ; 
    	dq.pop_front() ; 
    	for(auto v : G[u]) {
    		if(minimize(dist[v],dist[u]+1)) {
    			dq.pb(v) ; 
    		}
    	}
    }
	cout << (dist[n]==inf ?-1 : dist[n]/2 + 1) ; 
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
    return 0;
}