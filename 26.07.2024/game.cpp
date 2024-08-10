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

const int N = 7e2 + 5 ;
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
int a[N] ; 
ll dp[N][N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

ll sum(int x) {
	ll s = 0 ;
	while(x) {
		s+= (x%10) ; 
		x/=10 ; 
	}
	return s ; 
}

ll calc(int l,int r) {
	//cout << l << ' ' << r << endl ;
	if(l > r) return 0 ; 
	if(dp[l][r] > -inf) return dp[l][r] ; 
	ll &val = dp[l][r] = 0 ;
	FOR(k,l+1,r-1) {
		val = max(val , calc(l,k) + calc(k,r) + a[k] * (a[l] + a[r]) )  ;
	}
	//cout << l << ' ' << r << ' ' << dp[l][r] << endl ;
	return val ; 
}

void solve(void) {	
	FOR(i,0,n) FOR(j,i,n) dp[i][j] = -inf ; 
	dp[0][0] = 0 ;
	FOR(i,1,n) dp[i][i] = dp[i][i+1] = 0 ;
	cout << calc(1,n) ;
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