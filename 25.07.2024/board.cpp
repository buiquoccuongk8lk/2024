/*[продолжатьипродолжать]*/
/* ---------------------- *
 *   * Code by watbor     *
 *                        *
--------------------------*/

#include <bits/stdc++.h>
using namespace std ; 

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

const int N = 1e5 + 5 ;
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

int n , m ; 
int a[505][505] ; 
int pos[505][50005] ; 
int dp[505][505] ; 

void init(void) {
	cin >> n >> m ;
	FOR(i,1,n) {
		FOR(j,1,m) cin >> a[i][j] ; 
	}
}

void solve(void) {
	vi v ;
	FOR(i,1,n) FOR(j,1,m) v.pb(a[i][j]) ; 
	uni(v) ; 
	FOR(i,1,n) {
		FOR(j,1,m) {
			a[i][j] = lower_bound(all(v),a[i][j]) - v.begin() + 1 ; 
		}
	}	
	int ans = 0 ;
	FOR(i,1,n) {
		FOR(j,1,m) {
			dp[j][j] = max(dp[j][j],pos[j][a[i][j]]) ; 
			pos[j][a[i][j]] = i ; 
			maximize(ans , i - dp[j][j]) ; 
		}
		FOR(len,2,m) {
			FOR(j,1,m-len+1) {
				int l = j , r = j + len - 1 ; 
				dp[l][r] = max({dp[l][r],dp[l+1][r],dp[l][r-1],pos[l][a[i][r]],pos[r][a[i][l]]}) ; 
				maximize(ans , len * (i - dp[l][r]) ) ; 
			}
		}
	}
	
	cout << ans ; 
}

signed main(void) {
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