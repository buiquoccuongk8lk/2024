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

const int N = 1e2 + 5 ;
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
int a[N] , dp[N][N] , tmp[N] , cost[N][N] ;

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void solve(void) {
	FOR(i,1,n) {
		FOR(j,1,n) tmp[j] = a[j] ; 
		tmp[i] = 0 ; 
		int c = 0 ; 
		if(tmp[i]!=a[i]) c++ ; 	
		cost[i][i] = c ;
		FOR(j,i+1,n) {
			tmp[j] = tmp[j-1] + 1 ; 
			if(tmp[j]!=a[j]) c++ ; 
			cost[i][j] = c ; 
		}
	}
	FOR(k,1,n) {
		FOR(i,0,n) FOR(j,0,k) dp[i][j] = oo ; 
		FOR(i,1,n) dp[i][1] = cost[i][n] ;
		FORD(i,n,1) FOR(j,1,k) {
			FOR(v,1,i-1) {
				dp[v][j] = min(dp[v][j],dp[i][j-1] + cost[v][i-1]) ; 
			}
		}		
		cout << dp[1][k] << '\n' ; 
	}
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