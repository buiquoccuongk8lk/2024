/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;


#define int long long
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

const int N = 1e6 + 5 ;
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
int fish[N] ;
ll pre[N] ; 
struct bg {
	int place , len ; 
} ship[N] ; 
int dd[N] ; 
int t[N] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> fish[i] ; 
	cin >> m ;
	FOR(i,1,m) {
		cin >> ship[i].place >> ship[i].len ; 
		dd[ship[i].place] = ship[i].len ; 
	} 
}	

ll dp[N] ;  

void process(void) {

	FOR(i,1,n) pre[i] = pre[i-1] + fish[i] ; 

	dp[0] = 0 ; 

	int prev_prev_ship = - 1 ; 
	int prev_ship = -1 ;
	FOR(i,1,n) {
		dp[i] = max(dp[i],dp[i-1]) ;
		if(dd[i]) {
			prev_prev_ship = prev_ship ; 
			prev_ship = i ;
		} 
		int j = i - dd[prev_ship] + 1 ; 
		if( prev_prev_ship < j and j <= prev_ship ) dp[i] = max(dp[i] , dp[j-1] + pre[i] - pre[j-1] ) ; 
	}

	cout << dp[n] ; 
    	
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
    return (0 ^ 0) ; 
}