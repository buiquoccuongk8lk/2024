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

const int N = 2207 + 4 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD =  998244353;


tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
tct void add(WORK &x, const HARD &y) {x+=y ; if(x>=MOD)x-=MOD ;}

short r , c ; 
char a[N][N] ;

void init(void) {
	cin >> r >> c ; 
	FOR(i,1,r) FOR(j,1,c) cin >> a[i][j] ;
}

namespace sub {

	ll dp[N][N][5] ; 

	const short dx[] = { 0 , 1 , 1  , 2  , 1 } ; 
	const short dy[] = { 1 , 0 , 1  , 1  , 2 } ; 

	void solve(void) {

		FOR(dir,0,4) dp[1][1][dir] = 1 ;

		short lim = r + c ; 

		for(short s(0) ; s <= 4 ; s++) {
			short u = dx[s] + 1 ;
			short v = dy[s] + 1 ; 
			if(u>=1 and u<=r and v>=1 and v<=c and a[u][v]=='.') {
				//cout << u << ' ' << v << ' ' << s << endl ;
				add(dp[u][v][s],1) ; 
			}
		}

		for(short sum(0) ; sum <= lim ; sum++ ) {
			for(short y(1) ; y <= min(c,sum) ; y++ ) {
				short x = sum - y ; 
				if(x < 1 || y < 1 || x > r || y > c) continue ;
				if(x==1 and y==1) continue ;
				if(a[x][y]=='#') continue ;
				for(short dir(0) ; dir <= 4 ; dir++) {
					for(short new_dir(0) ; new_dir <= 4 ; new_dir++) {
						if(dir==new_dir) continue ; 
						short u = dx[new_dir] + x ; 
						short v = dy[new_dir] + y ; 
						if(u < 1 || u > r || v < 1 || v > c) continue ;
						if(a[u][v]=='#') continue ; 
						add(dp[u][v][new_dir],dp[x][y][dir]) ; 
					}
				}
			}
		}

		ll ans = 0 ; 
		FOR(dir,0,4) add(ans,dp[r][c][dir]) ;
		cout << ans ;
	}	

}

signed main(void) {
    #define TASK "changedir"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
   	sub::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}