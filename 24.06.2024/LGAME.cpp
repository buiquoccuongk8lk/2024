/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
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

const int N = 1e3 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
tct void add(WORK &x, const HARD &y) { x+=y ; if(x>=MOD)x-=MOD ; }

int n , S ; 
int a[N] ;
ll dp[N] ; 
ll leftWays[N][10005] , rightWays[N][10005] ;

void init(void) {
	cin >> n >> S ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void precalc(void) {
    leftWays[0][0] = 1 ; 
    rightWays[n+1][0] = 1 ; 
    FOR(i,1,n) {
        FOR(j,0,S) {
            leftWays[i][j] = leftWays[i-1][j] ; 
            if(j >= a[i]) add(leftWays[i][j],leftWays[i-1][j-a[i]]) ; 
        }
    }
    FORD(i,n,1) {
        FOR(j,0,S) {
            rightWays[i][j] = rightWays[i+1][j] ; 
            if(j >= a[i]) add(rightWays[i][j],rightWays[i+1][j-a[i]]) ;
        }
    }
}

void process(void) {
    precalc() ; 
    FOR(i,1,n) {
        FOR(j,0,S) {
            ll leftSum = S - j ; 
            ll rightSum = S - a[i] - leftSum ; 
            if(leftSum >= 0 and rightSum >= 0) {
                dp[i] = (dp[i] + (leftWays[i-1][leftSum] * rightWays[i+1][rightSum])%MOD )%MOD ; 
            }
        }
    }
    FOR(i,1,n) cout << dp[i] << ' ' ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}