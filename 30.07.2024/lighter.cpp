/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 


#define         ll long long 
#define         fi first
#define         se second
#define         pb push_back
#define         ii pair<int,int>
#define         vii vector<ii>
#define         vi vector<int>
#define         endl '\n' 
#define         sz(a) (int)a.size()
#define         all(a) a.begin(),a.end()
#define         FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define         FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define         FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define         uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e6 + 5 ;
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

int n , a , b ; 
ll f[N] ;
int x[N] ;

void init() {
	cin >> n >> a >> b ; 
}

ll calc(int i,int j) {return max({ b + f[j/2] , a + f[i-j] , b + f[(j+1) / 2]}) ;}

void solve() {

	ll ans = inf ; 

	FOR(i,1,n) f[i] = inf ;
	f[0] = -inf ;
	f[1] = 0 ; 

	x[0] = 0 , x[1] = 1 ;

	FOR(i,2,n) {
		int j = x[i-1] ; 
		int tmp = calc(i,j) ;
		while(j < i && tmp >= calc(i,j+1)) {
			tmp = calc(i,j+1) ; 
			j++ ; 
		}
		f[i] = tmp ; 
		x[i] = j ; 
	}

	cout << f[4] ; 

	FOR(i,1,n-(n%2)) ans = min(ans,calc(n,i)) ; 

	cout << ans ;
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    init() ; 
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}