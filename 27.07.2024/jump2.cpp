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
const int M = 4e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

void add(int &x,const int &y) {
	x+=y ; 
	if(x>=mod) x-=mod ; 
}

void sub(int &x,const int &y) {
	x-=y ; 
	if(x<0) x+=mod ; 
}

int n , m , k ; 
int c[M][M] , a[M] , b[M] ; 
int dp[M][M] ; 

void init(void) {
	cin >> n >> m >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,m) cin >> b[i] ; 
	FOR(i,1,n) FOR(j,1,m) c[i][j] = 1 + (a[i] + b[j])%k ;
}

namespace sub1 {
	void solve(void) {	
		dp[1][1] = 1 ; 	
		FOR(i,1,n) {
			FOR(j,1,m) {
				FOR(v,j+1,m) {
					if(v - j <= c[i][j]) add(dp[i][v],dp[i][j]) ; 
					else break ; 
				}
				FOR(u,i+1,n) {
					if(u - i <= c[i][j]) add(dp[u][j],dp[i][j]) ; 
					else break ;
				}
			}
		}
		cout << dp[n][m] ; 
	}
}

namespace sub2 {
	int sum_row[M][M] , sum_col[M][M] ; 
	void UP(int i,int j) {
		add(sum_row[i][j],sum_row[i-1][j]) ; 
		add(sum_col[i][j],sum_col[i][j-1]) ;
		add(dp[i][j],(sum_row[i][j]+sum_col[i][j])%mod) ; 
	}
	void PUSH(int i,int j) {
		add(sum_row[i+1][j],dp[i][j]) ; sub(sum_row[min(n+1,c[i][j]+i+1)][j],dp[i][j]) ; 
		add(sum_col[i][j+1],dp[i][j]) ; sub(sum_col[i][min(m+1,c[i][j]+j+1)],dp[i][j]) ; 
	}
	void solve(void) {
		memset(dp,0,sizeof dp) ;
		dp[1][1] = 1 ; 
		FOR(i,1,n) FOR(j,1,m) {
			UP(i,j) ; 
			PUSH(i,j) ; 
		}
		cout << dp[n][m]%mod ; 
	}
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; 
    if(n <= 1e3 && m <= 1e3 && k <= 10) sub1::solve() ; 
  	else sub2::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}