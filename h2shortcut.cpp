#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 1e5 + 5 ;
const ll inf = 1e18 ;
const int oo = 2e9 ;

int n,m,T ;
int c[maxn] ;
vector<ii> g[maxn] ;
ll dist[maxn] ;
int t[maxn] ;
vector<int> G[maxn] ;
ll f[maxn] ;

void init(void) {
    cin >> n >> m >> T ;
    FOR(i,1,n) cin >> c[i] ;
    FOR(i,1,m) {
        int u,v,w ;
        cin >> u >> v >> w ;
        g[u].pb({v,w}) ;
        g[v].pb({u,w}) ;
    }
}

void dijkstra(void) {
    FOR(i,1,n) {
        dist[i] = inf , t[i] = oo ;
    }
    priority_queue<ii,vector<ii>,greater<ii>>pq ;
    pq.push({0 , 1}) ;
    dist[1] = 0 ;
    t[1] = 0 ;
    while(!pq.empty()) {
        int u = pq.top().se ;
        ll cost = pq.top().fi ;
        pq.pop() ;
        if(cost > dist[u]) continue ;
        for(auto [v,w] : g[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w ;
                t[v] = u  ;
                pq.push({ dist[v] , v }) ;
            } else if(dist[v] == dist[u] + w) {
                t[v] = min(t[v],u) ;
            }
        }
    }
}


void process(void) {

    dijkstra() ;

    FOR(i,1,n) {
        G[i].pb(t[i]) ;
        G[t[i]].pb(i) ;
    }

    function<void(int,int)>dfs = [&](int u,int par) {
        f[u] = c[u] ;
        for(auto v : G[u]) {
            if(v==par) continue ;
            dfs(v,u) ;
            f[u]+=f[v] ;
        }
    } ;

    dfs(1,1) ;

    ll ans = 0 ;
    ll sum = 0 ;

    FOR(i,1,n) sum+=dist[i] ;

    FOR(i,1,n) {
        cout << t[i] << endl ;
    }

    FOR(i,1,n) {
        if(dist[i]>T) ans = max(ans , (dist[i] - T) * f[i] ) ;
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
    init() ; process() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ;
}
