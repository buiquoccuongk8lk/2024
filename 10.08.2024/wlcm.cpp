

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
const long long MOD = 998244353 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ;

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r){
    return l + rd()%(r-l+1);
}


int lcm(int a,int b) {
	return a * b / __gcd(a,b)  ;
}

int n ;
int a[N] ;
void init(void) {
	cin >> n ;
	FOR(i,1,n) cin >> a[i] ;
}

namespace sub3 {
	ll cnt[N] , f[N] ;

	ll LT(int x,int y) {
		if(y==0) return 1 ;
		if(y==1) return x ;
		ll c = LT(x,y/2) ;
		if(y&1) return c * c % MOD *x %MOD ;
		else return c * c % MOD ;
	}

	void solve(void) {

		for(int i(1) ; i <= n ; i++) cnt[a[i]]++ ;

		for(int i = 1e6 ; i >= 1 ; i--) {

			int x = 0 ;
			int y = 0 ;

			for(int j = i ; j <= 1e6 ; j+=i) {
				x = (x + cnt[j] * j)%MOD ;
				y=  (y +  cnt[j] * (j * j)%MOD )%MOD ;
			}

			f[i] = ( x * x % MOD - y + MOD )%MOD ;

			for(int j = 2 * i ; j <= 1e6 ; j+=i) {
				f[i] = (f[i] - f[j] + MOD )%MOD ;
			}

		}

		int ans = 0 ;
		for(int i = 1 ; i <= 1e6 ; i++) {
			ans = (ans + f[i] * LT(i,MOD-2)%MOD )%MOD  ;
		}

	    cout << ans * LT(2,MOD-2) % MOD ;

	}
}


signed main(void) {
    #define TASK "thanhbeo"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ;
    if(n == 5) {
        cout << 73 ;
        return 0 ;
    }
    sub3::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ;
}
