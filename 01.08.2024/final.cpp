/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define int long long
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
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m , k , q ; 
int a[N] ; 
int b[N] ;

void init() {
	cin >> n >> m >> k >> q ; 
	FOR(i,1,n) cin >> a[i] ;
}

void solve() {
	sort(a+1,a+1+n) ; reverse(a+1,a+1+n) ; 
	int ans = 0 ; 
	int l = 1 , r = n ;
	
	while(l <= r) {
		int mid = (l+r)/2 ; 
		ll sum = 0 ; 
		FOR(i,1,n) {
			if(i <= q - 1 || i >= mid) {
				sum+= m ; 
				continue ; 
			}
			if(a[i] > a[mid] + m) {
				sum = -1 ; 
				break ; 
			} 

			sum+= a[mid] + m - a[i] ; 
		}
		if(sum >= m * k) {
			ans = mid ; 
			l = mid + 1 ; 
		} else {
			r = mid - 1 ; 
		}
	}
	cout << ans ; 
}

signed main() {
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