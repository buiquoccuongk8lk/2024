/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define ll long long 
#define fi first
#define int long long
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

const int N = 1e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m , k ; 
vii g[(int)1e5+5] ;
int dist[(int)1e5+5][105] ; 

void init() {
	cin >> n >> m >> k ;
	//cout << n << ' ' << m << ' ' << k << endl ;
	FOR(i,1,m) {
		int u , v , w ; cin >> u >> v >> w ; 
		g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
		//cout << u << ' ' << v << ' ' << w << endl ;
	}
}

void solve() {
	FOR(i,1,n)FOR(j,1,k)dist[i][j] = inf ; 
	dist[1][1] = 0 ; 
	priority_queue<ii,vector<ii>,greater<ii>>pq ; 
	pq.push({0 , 1}) ; 

	while(!pq.empty()) {
		int u = pq.top().se ; 
		int cost = pq.top().fi ; 
		pq.pop() ; 
		if(cost > dist[u][k]) continue ; 
		for(auto x : g[u]) {
			int v = x.fi , w = x.se ; 
			bool ok = true ; 
			FOR(i,1,k) if(cost + w == dist[v][i]) {
				ok = false ; break ; 
			}
			if(dist[v][k] > cost + w && ok) {
				dist[v][k] = cost + w ; 
				pq.push({cost + w , v}) ; 
				int pos = -1 ; 
				FORD(i,k,1) if(dist[v][i] > dist[v][k]) {
					pos = i ; 
				}
				if(pos!=-1) {
					FORD(i,k,pos+1) swap(dist[v][i],dist[v][i-1]) ; 
				}
			}
		}
	}		
	if(dist[n][1] >= inf) {
		cout << - 1 ; 
		return ; 
	}
	FOR(i,1,k) cout << (dist[n][i] >= inf ? -1 : dist[n][i]) << ' ' ;
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}