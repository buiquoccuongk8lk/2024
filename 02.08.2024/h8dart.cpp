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

int n ;
struct KE {
	int v , w1 ;
} ;
vector<KE> g[N] ;  
char ty[60] ; 
ll dist[N] ;
struct PQ {
	int u ; 
	ll cost ; 
	bool operator <(const PQ &x) const {
		return cost > x.cost ; 
	}
} ; 

void dijk() {
	FOR(i,1,2*n)dist[i] = inf ; 
	priority_queue<PQ,vector<PQ>>pq ; 
	dist[n] = 0 ;
	dist[2*n] = 0 ; 
	pq.push({2 * n , 0 }) ; 
	pq.push({n , 0 }) ; 
	while(!pq.empty()) {
		int u = pq.top().u ; 
		ll cost = pq.top().cost ; 
		pq.pop() ; 
		if(cost > dist[u]) continue ; 
		for(auto [v,w] : g[u]) {
			if(minimize(dist[v],dist[u]+w)) {
				pq.push({v,dist[v]}) ; 
			}
		}
	}
}

void solve() {
	dijk() ; 
	cout << min(dist[1],dist[n+1]) ; 
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
	cin >> n ; 
	char x ; int u , v , w1 , w2 ;
	while(cin >> u >> v >> w1 >> w2 >> x) {
		if(x=='G')u+=n ;
		else v+=n ; 
		g[u].pb({v,w1}) ; 
		g[v].pb({u,w2}) ; 
	}   
	solve() ;
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}