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
#define iii pair<ll,ii> 

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
vii g[N] ; 
ll dist[N][102] ; 
multiset<ll> best[N] ;

void solve() {
	priority_queue<iii,vector<iii>>pq ; 
	FOR(i,1,n)FOR(j,0,k)dist[i][j] = inf ; 	
	dist[1][1] = 0 ;
	pq.push({0 , {1 , 1}}) ; 
	while(!pq.empty()) {
		int u = pq.top().se.fi ; 
		int pos = pq.top().se.se ;
		ll cost = pq.top().fi;
		pq.pop();
		if (cost > dist[u][pos]) continue;
		for(ii x : g[u]) {
			FOR(i,1,k) {
				if (dist[x.fi][i-1] == dist[u][pos]+x.se) break;
				else if (dist[x.fi][i] > dist[u][pos]+x.se) {
					FORD(j,k,i+1) {
						dist[x.fi][j] = dist[x.fi][j-1];
						if (dist[x.fi][i] != inf) pq.push({dist[x.fi][j],{x.fi,j}});
					}
					dist[x.fi][i] = dist[u][pos]+x.se;
					pq.push({dist[x.fi][i],{x.fi,i}});
				}
			}
		}
	}
	FOR(i,1,k) cout << dist[n][i] << ' ' ;
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n >> m >> k ; 
    FOR(i,1,m) {
    	int u , v , w ; cin >> u >> v >> w ; 
    	g[u].emplace_back(ii{v,w}) ; g[v].emplace_back(ii{u,w}) ; 
    }
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}