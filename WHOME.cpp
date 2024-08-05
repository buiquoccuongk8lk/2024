/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define tct template<class MITSURII,class CHANN>

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

int n , m , P , C ; 
int a[N] , s[N] ; 
ll dp[N][(int)(1<<6)] ; 
void init(void) {
	cin >> n >> m >> P >> C ; 
	FOR(i,1,n) cin >> a[i] ; 
	FOR(i,1,m) cin >> s[i] ;
}

void solve(void) {
	memset(dp,-0x3f3f3f,sizeof dp) ; 	
	dp[0][0] = 0 ;
	sort(a+1,a+1+n) ; 
	FOR(i,1,n) {
		FOR(mask,0,(1<<m)-1) {
			dp[i][mask] = dp[i-1][mask] ; 
			FOR(j,0,m-1) if((mask>>j)&1) {
				if(i >= s[j+1]) {
					maximize(dp[i][mask],dp[i-s[j+1]][mask^(1<<j)] + P - (a[i] - a[i - s[j+1] + 1]) * (a[i] - a[i - s[j+1] + 1]) * C) ;
					maximize(dp[i][mask],dp[i-s[j+1]][mask] + P - (a[i] - a[i -s[j+1]+1]) * (a[i]-a[i-s[j+1]+1]) * C) ;
				}
			}
		}
	}
	cout << dp[n][(1<<m)-1] ; 
}

signed main(void) {
    #define TASK "WHOME"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}