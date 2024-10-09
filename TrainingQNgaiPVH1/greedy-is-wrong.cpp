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

int n ;
char a[55][55] ;
char b[55][55] ; 

void init(void) {
	cin >> n ;
	FOR(i,1,n) {
		FOR(j,1,n) {
			cin >> a[i][j] ;
		}
	}
}


void process(void) {

	bool ok = true ; 

	FOR(j,1,n) {
		FOR(i,1, n - (n/2 + 1) + 1) { 
			int cntW = 0 ; 
			FOR(x,i,i + (n/2 + 1) - 1) {
				cntW+=(a[x][j]=='W') ; 
			}
			if(cntW==0 || cntW==(n/2 + 1)) {
				ok = false ; 
				break ; 
			}
		}
	}
	if(ok) {
		cout << 0 ; 
		return  ;
	}

	FOR(i,1,n) {
		// bien hang i thanh den 
		ok = true ; 
		FOR(x,1,n) FOR(y,1,n) b[x][y] = a[x][y] ; 

		FOR(j,1,n) b[i][j] = 'W' ; 

		FOR(j,1,n) {
			FOR(l,1, n - (n/2 + 1) + 1) { 
				int cntW = 0 ; 
				FOR(x,l,l + (n/2 + 1) - 1) {
					cntW+=(b[x][j]=='W') ; 
				}
				if(cntW==0 || cntW==(n/2 + 1)) {
					ok = false ; 
					break ; 
				}
			}
		}
		//cout << i << ' ' << ok << endl ;
		if(ok) {
			cout << 1 ; 
			return ;
		}
		FOR(x,1,n) FOR(y,1,n) b[x][y] = a[x][y] ; 

		ok = true ; 
		FOR(j,1,n) b[i][j] = 'B' ; 

		FOR(j,1,n) {
			FOR(l,1,n-(n/2 + 1)+1) { 
				int cntW = 0 ; 
				FOR(x,l,l + (n/2 + 1) - 1) {
					cntW+=(b[x][j]=='W') ; 
				}
				if(cntW==0 || cntW==(n/2 + 1)) {
					ok = false ; 
					break ; 
				}
			}
		}

		if(ok) {
			cout << 1 ; 
			return ;
		}
	}

	cout << 2 ;
}

signed main(void) {
    #define TASK "greedy-is-wrong"
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