/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define int long long
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,ll>
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

int n,m,q ;
struct Edges {
	int u ,v , w , id ; 
} e[N] ; 
struct Queries {
	int t , w , id ; 
} Q[N] ; 
vii g[N] ;

void init(void) {
	cin >> n >> m >> q ; 
	FOR(i,1,m) {
		int u , v , w ; 
		cin >> u >> v >> w ; 
		g[u].pb({v,w}) ; g[v].pb({u,w}) ;
		e[i] = {u,v,w,i} ; 
	}
	FOR(i,1,q) {
		cin >> Q[i].t >> Q[i].w ; 
		Q[i].id = i ;
	}
}

namespace sub1 {

	ll dist1[N],dist2[N] ;

	void dijkstra(int st,ll dist[]) {
		priority_queue<ii,vector<ii>,greater<ii>>pq ; 
		FOR(i,1,n) dist[i] = inf ; 
		dist[st] = 0 ; 
		pq.push({dist[st],st}) ;
		while(!pq.empty()) {
			int u = pq.top().se ; 
			ll cost = pq.top().fi ; 
			pq.pop() ; 
			if(cost > dist[u]) continue ; 
			for(auto [v,w] : g[u]) {
				if(minimize(dist[v],dist[u]+w)) {
					pq.push({dist[v],v}) ; 
				}
			}
		}
	}

	int calc(int x) {
		int ret = 0 ; 
		FOR(i,1,n) if(dist1[i] <= dist1[x] && dist2[i] <= dist2[x]) ret++ ; 
		return ret ; 
	}

	void solve(void) {
		
		FOR(love,1,q) {
			int t = Q[love].t , w = Q[love].w ; 
			int u = e[t].u , v = e[t].v ; 
			g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
			dijkstra(1,dist1) ; 
			dijkstra(2,dist2) ; 
			cout << calc(u) << ' ' << calc(v) << '\n' ; 
			g[u].pop_back() ; g[v].pop_back() ; 
		}	

	}

}

namespace sub2 {

	ll dist1[N] , dist2[N] ; 

	void dijkstra(int st,ll dist[]) {
		priority_queue<ii,vector<ii>,greater<ii>>pq ; 
		FOR(i,1,n) dist[i] = inf ; 

		dist[st] = 0 ; 
		pq.push({dist[st],st}) ;

		while(!pq.empty()) {
			int u = pq.top().se ; 
			ll cost = pq.top().fi ; 
			pq.pop() ; 
			if(cost > dist[u]) continue ; 
			for(auto [v,w] : g[u]) {
				if(minimize(dist[v],dist[u]+w)) {
					pq.push({dist[v],v}) ; 
				}
			}
		}
	}	

	struct info {
		int u ; 
		ll w1 , w2 ; 
		int id ;
		info(int u = 0,ll w1 = 0,ll w2 = 0,int id = 0) : u(u),w1(w1),w2(w2),id(id) {}
		bool operator <(const info &e) const {
			if(w1==e.w1) return id < e.id ; 
			else return w1 < e.w1 ; 
		} 
	} ;
	ii ans[N] ;
	int bit[2 * N] ;	
	int VAL ; 
	int dd[N] ;

	void up(int u,int val) {
		for(int i = u ; i <= VAL ; i+=i&-i) bit[i]+=val ; 
	}

	int get(int u) {
		int sum = 0 ; 
		for(int i = u ; i ; i-=i&-i) sum+= bit[i] ; 
		return sum ; 
	}

	void solve(void) {
		dijkstra(1,dist1) ; dijkstra(2,dist2) ;

		vector<info> vec ;
		FOR(i,1,n) vec.pb({i,dist1[i],dist2[i],0}) ; 
		
		FOR(i,1,q) {
			int t = Q[i].t , w = Q[i].w ; 
			int u = e[t].u , v = e[t].v ; 

			int d1unew = min(dist1[u],dist1[v] + w) ; 
			int d2unew = min(dist2[u],dist2[v] + w) ; 
			int d1vnew = min(dist1[v],dist1[u] + w) ; 
			int d2vnew = min(dist2[v],dist2[u] + w) ; 

			vec.pb({u,d1unew,d2unew,i}) ; 
			vec.pb({v,d1vnew,d2vnew,i}) ; 		
		}
 	
		vi v ; 
		for(auto x : vec) v.pb(x.w2) ; 
		uni(v) ; 
		VAL = v.size() ;
		sort(all(vec)) ;

		int type ; 
		for(info x : vec) {
                int u = x.u,id = x.id;
                int k = lower_bound(all(v),x.w2) - v.begin() + 1;
                if(!id) up(k,1),dd[u] = 1;
                else{
                    if(u == e[Q[id].t].u) type = 1;
                    else type = 2;
                    int ok = dd[u],res = get(k);

                    if(!ok) ++res;
                    else if(ok && x.w2 < dist2[u]) ++res;

                    if(type == 1) ans[id].fi = res;
                    else ans[id].se = res;
                }
        }

        FOR(i,1,q) cout << ans[i].fi << " " << ans[i].se << "\n";
	}
}

signed main(void) {
    #define TASK "IMPEVAL"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    //if(n <= 1000 && q <= 1000) sub1::solve() ; 
    sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}