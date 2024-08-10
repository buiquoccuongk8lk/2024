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

string s , t ; 
int n , m ; 
ll dp[5005][5005] ;
int pa[N] , pb[N] ;
int ida[N] , idb[N] ;
ll preA[5005][28] , preB[5005][28] ; 

struct bg {
	int x ; int sl ; 
}a[N] , b[N] ;

void init(void) {
	cin >> s ;
	cin >> t ; 
}

void process(void) {

	n = 0 ;

	m = 0 ;

	FOR(i,0,sz(s)-1) {
		if(s[i] >= 'a' and s[i] <= 'z') {
			n++ ; 
			a[n].x = s[i] - 'a' + 1 ; 
		} else {
			a[n].sl = a[n].sl * 10 + s[i] - '0' ;
		}
	}

	FOR(i,0,sz(t)-1) {
		if(t[i] >= 'a' and t[i] <= 'z') {
			m++ ; 
			b[m].x = t[i] - 'a' + 1 ;
		} else {
			b[m].sl = b[m].sl * 10 + t[i] - '0' ;
		}
	}

	dp[0][0] = 0 ; 

	FOR(i,1,n) FOR(j,1,m) {
		if(a[i].x==b[j].x) {

			dp[i][j] = min(a[i].sl,b[j].sl) ; 

			//if(a[i].sl == b[j].sl) {
				int u = i - 1 ; 
				int v = j - 1 ;
				while(a[u].x == b[v].x and u >= 1 and v >= 1 ) {
					dp[i][j] += min(a[u].sl , b[v].sl) ;
					if(a[u].sl == b[v].sl) {
						u-- ; 
						v-- ;
					}else break ; 
 				}
			//}

		}
	}

	ll ans = 0 ;
	FOR(i,1,n) FOR(j,1,m) maximize(ans,dp[i][j]) ; 
	cout << ans; 
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