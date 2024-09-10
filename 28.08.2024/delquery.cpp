// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 2e5 + 5 ;
const int oo = 2e9 ;

int n , m , q ;
ii e[MAXN] ; 
struct Queries {
    int t , u ;
} Q[MAXN] ;

void init() {
    cin >> n >> m ; 
    FOR(i,1,m) cin >> e[i].fi >> e[i].se ; 
    cin >> q ; 
    FOR(i,1,q) cin >> Q[i].t >>  Q[i].u ;
}

namespace subtask_1 {
    int adj[5005][5005] ; 
    int res[MAXN] , dist[MAXN] , degIn[MAXN] ;

    void bfs(int st) {
        FOR(i,1,n)dist[i] = 2e9 ; 
        queue<int> q ;
        q.push(1) ; 
        dist[1] = 0 ; 
        while(!q.empty()) {
            int u = q.front(); 
            q.pop() ; 
            FOR(v,1,n) if(adj[u][v] > 0) {
                if(mini(dist[v],dist[u]+1)) q.push(v) ; 
            }
        }
        FOR(i,1,n) res[i] = 0 ;
        FOR(i,1,m) {
            int u = e[i].fi , v = e[i].se ; 
            if(adj[u][v] > 0 && dist[v]!=oo) res[v]++ ;
        }
    }

    void solve() {
        FOR(i,1,m) adj[e[i].fi][e[i].se]++ ; 
        bfs(1) ; 
        FOR(i,1,q) {
            int t ; t = Q[i].t ;
            if(t==1) {      
                int id = Q[i].u ;
                int u = e[id].fi , v = e[id].se ; 
                adj[u][v]-- ; 
                if(adj[u][v]==0) {
                    bfs(1) ; 
                } else {
                    if(dist[v]!=oo) res[v]-- ; 
                }
            } else {
                int u = Q[i].u ;
                cout << res[u] << '\n' ; 
            }

        }
    }
}

namespace subtask_2 {
    int dist[MAXN] ; 
    vii g[MAXN] ;
    vector<pair<int,ii>> adj ; 
    int res[MAXN] ;
    bool del[MAXN] ;

    void dijk() {
        priority_queue<ii,vector<ii>,greater<ii>>pq ;
        FOR(i,1,n) dist[i] = 2e9 ; 
        dist[1] = - (q + 1) ;
        pq.push({-q-1,1}) ; 
        while(!pq.empty()) {
            int u = pq.top().se ;
            int cost = pq.top().fi ; 
            pq.pop() ;
            //if(cost > dist[u]) continue ; 
            for(auto x : g[u]) {
                int v = x.fi , w = x.se ; 
                if(dist[v] > max(w,cost)) {
                    dist[v] = max(w,cost) ;
                    pq.push({dist[v],v}) ; 
                }
            }
        }
    }  

    void solve() { 
        FOR(i,1,m) adj.pb({0,{e[i].fi,e[i].se}}) ;  
        FOR(i,1,q) {
            if(Q[i].t == 1) {
                adj[Q[i].u-1].fi = i ; 
            }
        }
        FOR(i,1,m) {
            int z = adj[i-1].fi , u = adj[i-1].se.fi , v = adj[i-1].se.se ; 
            if(z == 0) z = q + 1 ;
            z = -z ; 
            g[u].pb({v,z}) ; 
        }
        dijk() ;
        FOR(i,1,m) if(dist[i]!=2e9) res[e[i].se]++ ; 
        FOR(i,1,q) {
            if(Q[i].t==1) {
                int v = adj[Q[i].u - 1].se.se ;
                int c = - dist[adj[Q[i].u - 1].se.fi ] ;
                if(c!=-2e9) res[v]-- ; 
                del[Q[i].u] = 1 ;
            } else {
                int c = - dist[Q[i].u] ;
                cout << ( (c <= i || -c == 2e9) ? 0 : res[Q[i].u]) << '\n' ;
            }
        }
    }
}

signed main() {
    #define task "delquery"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    if(n <= 500) subtask_1::solve() ;
    else subtask_2::solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */