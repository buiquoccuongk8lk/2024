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


	FOR(i,1,n) {
		FOR(j,1,26) {
			preA[i][j] = preA[i-1][j] + (a[i].x == j) * a[i].sl ;
		}
	}

	FOR(i,1,m) {
		FOR(j,1,26) {
			preB[i][j] = preB[i-1][j] + (b[i].x == j) * b[i].sl ; 
		}
	}

	FOR(c,1,26) {
		ida[c] = 0 ;
	}

	FOR(i,1,n) {
		pa[i] = ida[a[i].x] ; 
		ida[a[i].x] = i ;
	}

	FOR(c,1,26) {
		idb[c] = 0 ;
	}

	FOR(i,1,m) {
		pb[i] = idb[b[i].x] ; 
		idb[b[i].x] = i;
	}


	FOR(i,1,n) FOR(j,1,m) {

		dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;

		if(a[i].x == b[j].x) {
			int u = i ; int v = j ; int c = a[i].x ;

			while(1) {
				if(preA[i][c] - preA[u-1][c] > preB[j][c] - preB[v-1][c] ) {
					if(v and u) maximize(dp[i][j] , dp[u-1][v-1] + preB[j][c] - preB[v-1][c] )  ;
					v = pb[v] ; 
					if(v == 0) break ;
				} else {
					if(u and v) maximize(dp[i][j] , dp[u-1][v-1] + preA[i][c] - preA[u-1][c] ) ; 
					u = pa[u] ; 
					if(u==0) break ; 
				}
			}

		}

	}

	cout << dp[n][m] ;
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