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

const int N = 1e5 + 5 ;
const int LO = __lg(N) + 1 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , q ; 
string s ;
int pre[N] , rmq[N][LO] ; 

void init(void) {
	cin >> n >> q ; 
	cin >> s ; 
	s = "*" + s ; 
}

int get(int l,int r) {
	int k = __lg(r-l+1) ; 
	return min(rmq[l][k],rmq[r-(1<<k) + 1][k]) ; 
}

void process(void) {

	FOR(i,1,n) pre[i] = pre[i-1] + (s[i] == '(' ? 1 : -1) ; 

	FOR(i,1,n) rmq[i][0] = pre[i] ; 

	for(int j(1) ; (1<<j) <= n ; j++) {
		for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
			rmq[i][j] = min(rmq[i][j-1] , rmq[i + (1 << (j-1))][j-1]) ; 
		}
	}

	while(q--) {
		int l , r ; 
		cin >> l >> r ; 
		cout << ( get(l,r) >= pre[l-1] and pre[r] == pre[l-1] ? "YES" : "NO") << endl ; 
	}

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