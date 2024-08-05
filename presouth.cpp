/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define         ll long long 
#define         fi first
#define         se second
#define         pb push_back
#define         ii pair<int,int>
#define         vii vector<ii>
#define         vi vector<int>
#define         endl '\n' 
#define         sz(a) (int)a.size()
#define         all(a) a.begin(),a.end()
#define         FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define         FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define         FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define         uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

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

int n ; 
int w[N] ; 
vi g[N] ;

void init() {
    cin >> n ; 
    FOR(i,1,n) cin >> w[i] ; 
    FOR(i,1,n-1) {
        int u , v ; cin >> u >> v ; 
        g[u].pb(v) ; g[v].pb(u) ; 
    }
}

namespace sub2 {
    ll dp[N][5] ;
    ll tmp[5] ; 

    void dfs(int u,int par) {
        dp[u][1] = -w[u] ; 
        dp[u][2] = w[u] ; 
        dp[u][0] = 0 ;
        for(auto v : g[u]) if(v!=par) {
            dfs(v,u) ; 
            tmp[0] = dp[u][0] + dp[v][3] ; 
            tmp[1] = max(dp[u][1] + dp[v][3], dp[u][0] + dp[v][1]) ;
            tmp[2] = max(dp[u][2] + dp[v][3], dp[u][0] + dp[v][2]) ; 
            tmp[3] = max({dp[u][0] + dp[v][3], dp[u][3] + dp[v][3], dp[u][1] + dp[v][2], dp[u][2] + dp[v][1]}) ; 
            dp[u][0] = tmp[0] ; 
            dp[u][1] = tmp[1] ; 
            dp[u][2] = tmp[2] ; 
            dp[u][3] = tmp[3] ; 
        }
    }   

    void solve() {
        dfs(1,1) ; 
        cout << dp[1][3] ; 
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
    sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}