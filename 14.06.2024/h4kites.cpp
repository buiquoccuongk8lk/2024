/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define int long long
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
tct void add(WORK &x,const HARD &y) {x+=y ; if(x>=y)x-=MOD ;}

int n ; 
struct point {
	int x ; 
	int y ; 
} ;
point a[N] , b[N] ;

void init(void) {
	cin >> n ;
	FOR(i,1,n) {
		cin >> a[i].x ;
		a[i].y = 0 ;
	}
	FOR(i,1,n) {
		cin >> b[i].x >> b[i].y ; 
	}
}

namespace sub {
	// goi dp[i][j][l][r] la so cach xep a[i..j] va b[l...r] 
	ll dp[55][55][55][55] ; 
	int dd[55][55][55][55] ;
	int ccw(point a,point b,point c) {
		return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x) ; 
	}
	ll calc(int i,int j,int l,int r) {
		if(i+1==j) return 1 ; 
		if(dd[i][j][l][r]) return dp[i][j][l][r] ; 
		ll &val = dp[i][j][l][r] ; 
		dd[i][j][l][r] = 1 ;
		val = 0 ; 
		int pos_kite = -1 ;
		point M = {-1,-1} ;
		FOR(p,1,n) {
			if(ccw(a[i],b[p],b[l]) > 0 and ccw(a[j],b[p],b[r]) < 0 and b[p].y <= b[l].y and b[p].y <= b[r].y) {
				if(M.y < b[p].y) {
					M = b[p] ; 
					pos_kite = p ;
				}
			}
		}
		if(pos_kite!=-1) {
			FOR(k,i+1,j-1) {
				val = val + calc(i,k,l,pos_kite) * calc(k,j,pos_kite,r) %MOD ; 
				val%=MOD ;
			}
		}else val = 0 ;
		return val ;
	}

	void solve(void) {
		a[0] = {(int)-1 , 0} ;
		b[0] = {(int)-1e4 + 3 , (int)1e4 + 3} ;
		a[n+1] = {(int)1e4 + 3 , 0 } ; 
		b[n+1] = {(int)1e4 + 3 , (int)1e4 + 3} ;  
		sort(a+1,a+1+n,[](point u,point v) {
			return u.x < v.x ;
		}) ;
		cout << calc(0,n+1,0,n+1) ; 
	}

}

signed main(void) {
    #define TASK "h4kites"
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