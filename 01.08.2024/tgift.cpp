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

const int N = 2e5 + 5 ;
const int LO = __lg(N) + 1 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}


/*  Solution : Set + LCA
    để ý rằng đáp án luôn tồn tại ở dạng (i,i+1) vì a[i] với a[i+1] 
    bởi ít nhất phải thuộc 2 cây con khác nhau gốc i
    -> chỉ cần quan tâm tới 2 thằng liên tiếp
*/

int n , m , q ; 
int a[N] ;
vi g[N] ; 

void init() {   
    cin >> n >> m >> q ; 
    FOR(i,1,n-1) {
        int u , v ; cin >> u >> v ; 
        g[u].pb(v) ; g[v].pb(u) ; 
    }
    FOR(i,1,m) cin >> a[i] ; 
}

struct {    
    int P[N][LO] , h[N] ; 
    void dfs(int u,int par) {
        for(auto v : g[u]) if(v!=par) {
            h[v] = h[u] + 1 ; 
            P[v][0] = u ;
            dfs(v,u) ; 
        }
    }   
    void init() {
        dfs(1,1) ; 
        for(int j(1) ; (1<<j) <= n ; j++) {
            FOR(i,1,n) {
                int x = P[i][j-1] ; 
                P[i][j] = P[x][j-1] ; 
            }
        }
    }
    int find(int u,int v) {
        if(u==v) return u ; 
        if(h[u]<h[v])swap(u,v) ; 
        int z = __lg(h[u]) ; 
        FORD(s,z,0)if((h[u]-h[v])>=(1<<s)) {
            u = P[u][s] ; 
        }
        if(u==v)return u ; 
        FORD(s,z,0)if(P[u][s]!=P[v][s]) {
            u = P[u][s] ; 
            v = P[v][s] ; 
        }
        return P[u][0] ; 
    }
} LCA ; 

set<int> pos[N] , lca[N] ; 
void solve() {
    LCA.init() ; 
    FOR(i,1,m) pos[a[i]].insert(i) ;    
    FOR(i,1,m-1) lca[LCA.find(a[i],a[i+1])].insert(i) ; 

    while(q--) {
        int t ; cin >> t ;
        if(t==1) {
            int i , u ; 
            cin >> i >> u ; 
            pos[a[i]].erase(i) ; 
            pos[u].insert(i) ; 
            if(i < m) {
                int old_LCA = LCA.find(a[i],a[i+1]) ; 
                lca[old_LCA].erase(i) ; 
            }
            if(i >= 2) {
                int old_LCA = LCA.find(a[i],a[i-1]) ; 
                lca[old_LCA].erase(i-1) ; 
            }
            a[i] = u ; 
            if(i < m) {
                int new_LCA = LCA.find(a[i],a[i+1]) ; 
                lca[new_LCA].insert(i) ; 
            }
            if(i >= 2) {
                int new_LCA = LCA.find(a[i],a[i-1]) ; 
                lca[new_LCA].insert(i-1) ; 
            }
        } else {
            int l , r , u ; 
            cin >> l >> r >> u ; 
            int cur_val = 0 ; 
            if(!pos[u].empty()) {
                auto it = pos[u].lower_bound(l) ; 
                cur_val = *it ; 
                if(! ( cur_val >= l && cur_val <= r) ) cur_val = 0 ;  
            } 
            if(cur_val) cout << cur_val << ' ' << cur_val << '\n' ; 
            else {
                auto it = lca[u].lower_bound(l) ; 
                cur_val = *it ; 
                if(cur_val >= l && cur_val < r) cout << cur_val << ' ' << cur_val + 1 << '\n' ; 
                else cout << -1 << ' '  << -1 << '\n' ; 
            } 
        }
    }

}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}