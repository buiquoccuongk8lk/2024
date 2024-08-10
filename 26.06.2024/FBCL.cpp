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
char a[N] ; 

void init(void) {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

void process(void) {
	
	string ans ; 

	int l = 1 ; 
	int r = n ; 

	while(l <= r) {
		if(a[l] < a[r]) {
			ans.pb(a[l]) ; 
			l++ ; 
		} else if(a[l] > a[r]) {
			ans.pb(a[r]) ; 
			r-- ; 
		} else if(a[l] == a[r]) {
			int posL = l ; 
			int posR = r ; 
			while(posR - posL + 1 > 2) {
				if(a[posL]==a[posR]) {
					posL++ ; 
					posR-- ; 
				} else break ; 
			}
			if(a[posL] < a[posR]) {
				ans.pb(a[l]) ; 
				l++ ; 
			} else {
				ans.pb(a[r]) ; 
				r-- ;
			}
		}
	}

	ans = "*" + ans ; 
	
	FOR(i,1,sz(ans)-1) {
		cout << ans[i] ; 
		if(i%80==0) cout << endl ;
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