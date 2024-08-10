/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

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

struct point {
    int x , y ; 
} H[M] , G[M] ; 
int n , m ; 
ll dp[M][M][3] ;

void init(void) {
    cin >> n >> m ; 
    FOR(i,1,n) cin >> H[i].x >> H[i].y ; 
    FOR(i,1,m) cin >> G[i].x >> G[i].y ; 
}

ll dist(point a,point b) {
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) ; 
}

void solve(void) {
    FOR(i,0,n) FOR(j,0,m) FOR(t,0,1) dp[i][j][t] = inf ; 
    dp[1][0][0] = dp[0][0][0] = dp[0][0][1] = 0 ;
    FOR(i,2,n) dp[i][0][0] = dp[i-1][0][0] + dist(H[i-1],H[i]) ;
    FOR(i,1,n) FOR(j,1,m) {
        minimize(dp[i][j][0],dp[i-1][j][0] + dist(H[i-1],H[i])) ;
        minimize(dp[i][j][0],dp[i-1][j][1] + dist(G[j],H[i])) ; 
        minimize(dp[i][j][1],dp[i][j-1][0] + dist(H[i],G[j])) ;
        minimize(dp[i][j][1],dp[i][j-1][1] + dist(G[j-1],G[j])) ;  
    }
    cout << dp[n][m][0] ;
}

signed main(void) {
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