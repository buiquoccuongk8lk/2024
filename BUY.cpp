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

const int N = 2e5 + 5 ;
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

int n , m , k ;
int a[N] , ones[N] ; 
ll pre[N] ; 

void init(void) {
	cin >> n >> m >> k ;
	FOR(i,1,n) cin >> a[i] ;  
}

void solve(void) {
	int sz = 0 ; 
	FOR(i,1,n) if(a[i]) {
		ones[++sz] = i - 1 ; 
	}
	n = sz ; 
	if(m > n) {
		cout << -1 ; 
		return ; 
	}
	ll ans = inf ; 

	FOR(i,1,n) pre[i] = pre[i-1] + ones[i] ; 	

	ll sum = ones[1] ;
	FOR(i,2,m) sum = sum + 1ll * (i - 1) * k * abs(ones[i] - ones[i-1]) ; 

	ans = sum ; 

	FOR(i,m+1,n) {
		int j = i - m + 1 ; 
		sum = ones[j] - 1ll * k * (pre[i-1] - pre[j-1]) + 1ll * (m - 1) * k * ones[i] ; 
		ans = min(ans,sum) ; 
		//cout << sum << endl ;
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
    init() ; solve() ;
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}