/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 
#define int long long
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

const int N = 3e5 + 5 ;
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

int n , q ; 
struct Edges {
    int u , v , w ; 
} e[N] ; 
struct Queries {
    int id , w ;
} Q[N] ;
vii g[N] ;

namespace subtask_1 {
    bool check() {return n<=3e3 && q <= 3e3;} 
    int W[3005][3005] ; 
    ll f[3005] ; 
    void dfs(int u,int par) {
        for(auto x : g[u]) {
            int v = x.fi ; 
            if(v==par) continue ;
            f[v] = f[u] + W[u][v] ;
            dfs(v,u) ; 
        }
    }
    void solve() {
        FOR(i,1,n-1) {
            int u = e[i].u , v = e[i].v , w = e[i].w ;
            W[u][v] = W[v][u] = w ; 
        }
        FOR(t,1,q) {
            int id = Q[t].id , w = Q[t].w ;
            int u = e[id].u , v = e[id].v ; 
            W[u][v] = W[v][u] = w ; 
            FOR(i,1,n) f[i] = 0 ;
            dfs(1,1) ; 
            int root = 1 , ma = 0 ;
            FOR(i,1,n) if(maximize(ma,f[i])) root = i ;
            FOR(i,1,n) f[i] = 0 ; 
            dfs(root,root) ; 
            cout << *max_element(f+1,f+1+n) << '\n' ;
        }
    }
}

namespace subtask_2 {   
    int P[N][LO] ; 
    ll sum[N][LO] , h[N] , f[N] ;
    ll maOut = 0 ;  
    vi gg[N] ; 
    struct KE {
        int v , w , id ; 
    } ;
    vector<KE> G[N] ;
    bool check() {
        FOR(i,2,q) if(Q[i-1].id!=Q[i].id) return 0 ;
        return 1 ; 
    } 

    void dfs1(int u,int par) {
        for(auto [v,w,id] : G[u]) {
            if(id == Q[1].id) continue ; 
            if(v==par) continue ;
            h[v] = h[u] + w ;
            dfs1(v,u) ; 
            f[u] = max(f[u] , f[v] + w) ; 
        }
    }

    void solve() {  
        FOR(i,1,n-1) {
            auto [u,v,w] = e[i] ; 
            G[u].pb({v,w,i}) ; 
            G[v].pb({u,w,i}) ; 
        }
        int id = Q[1].id ; 
        int u = e[id].u , v = e[id].v ; 
        int maU = 0 , maV = 0 ;

        dfs1(u,u) ; 
        maU = f[u] ;
        FOR(i,1,n) f[i] = 0 ;

        dfs1(v,v) ; 
        maV = f[v] ; 
        FOR(i,1,n) f[i] = 0 ;

        FOR(i,1,n) h[i] = 0 ;

        int root = 0 , ma = 0 ;
        dfs1(u,u) ; 
        FOR(i,1,n) if(maximize(ma,h[i])) root = i ;
        dfs1(v,v) ; 
        FOR(i,1,n) if(maximize(ma,h[i])) root = i ;
        FOR(i,1,n) f[i] = 0 ;
        dfs1(root,root) ; 
        FOR(i,1,n) maximize(maOut,f[i]) ; 
        
        FOR(t,1,q) {
            int w = Q[t].w ; 
            cout << max(maOut,maU + maV + w) << '\n' ; 
        }
    }       
}

namespace subtask_3 {
    int par[N] ; 
    int w1[N] , w2[N] , res[N] , f[N] , child1[N] , child2[N] ;
    vii gg[N] ; 

    bool check() {
    	FOR(i,1,n) if(g[i].size() > 3) return 0 ; 
    	return 1 ; 
    }

    void dfs(int u,int p) {
        for(auto [v,w] : g[u]) if(v!=p) {
            par[v] = u ;
            dfs(v,u) ; 
        }
    }

    void nhay(int u,int v,int w) {
        int d = 0 , v1 = child1[u] , v2 = child2[u] ;
        for(auto [vv,ww] : gg[u]) {
            d++ ; 
            if(vv == v) {
                if(d == 1) {
                    w1[u] = w ; 
                    break ;
                } else w2[u] = w ; 
            }
        }
        v1 = child1[u] , v2 = child2[u] ; 
        f[u] = max( f[v1] + w1[u] , f[v2] + w2[u] ) ;
        while(u!=0) {
            v1 = child1[u] , v2 = child2[u] ; 
            res[u] = max(res[v1] , res[v2]) ; 
            res[u] = max(res[u] , f[v1] + f[v2] + w1[u] + w2[u]) ;  
            f[u] = max( f[v1] + w1[u] , f[v2] + w2[u] ) ; 
            u = par[u] ;
        } ;
    }

    void build(int u) {
        for(auto [v,w] : gg[u]) {
            build(v) ; 
            f[u] = max(f[u],f[v] + w) ; 
        }
        int  v1  = child1[u] , v2 = child2[u] ; 
        res[u] = max(res[u],f[u]) ; 
        res[u] = max(res[v1] , res[v2]) ; 
        res[u] = max(res[u] , f[v1] + f[v2] + w1[u] + w2[u]) ; 
    }

    void solve() {  
        dfs(1,1) ;
        FOR(i,1,n) {
            int d = 0 ;
            for(auto [v,w] : g[i]) if(i==par[v]) {
                d++ ; 
                if(d==1) w1[i] = w , child1[i] = v ;
                else w2[i] = w , child2[i] = v ;
                gg[i].push_back({v,w}) ;
            }
        }
        build(1) ;  
        FOR(t,1,q) {
            int id = Q[t].id , w = Q[t].w ; 
            int u = e[id].u , v = e[id].v ; 
            if(v==par[u]) swap(u,v) ; 
            nhay(u,v,w) ; 
            cout << res[1] << '\n' ; 
        }
    }
}

namespace subtask_4 {

	void solve() {


	}

}

signed main() {
    #define TASK "vtravel"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n >> q ;
    FOR(i,1,n-1) {
        int u , v , w ; cin >> u >> v >> w ; 
        e[i] = {u,v,w} ;
        g[u].pb({v,w}) ; g[v].pb({u,w}) ; 
    }    
    FOR(i,1,q) cin >> Q[i].id >> Q[i].w ; 
    /*if(subtask_1::check()) subtask_1::solve() ; 
    else if(subtask_2::check())*/ subtask_2::solve() ; 
   // else subtask_3::solve() ;
    //else subtask_4::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}