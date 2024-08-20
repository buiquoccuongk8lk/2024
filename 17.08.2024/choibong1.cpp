#include <bits/stdc++.h>
using namespace std ; 
#define int long long

typedef long long ll ;
typedef pair<int, int> ii ;
typedef vector<int> vi ;
typedef vector<ii> vii ; 

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(a) a.begin(),a.end()

#define FOR(i,a,b) for(int i(a) ; i <= (int)(b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)(b) ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define sz(a) (int)a.size()
#define MASK(a) (1ll << (i))
#define BIT(mask,i) ((mask>>i)&1)

template<class X, class Y> bool maxi(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool mini(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}

const int MAXN = 5e2 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n ; 
int a[MAXN] ; 
int dp[MAXN][MAXN] ;

void init() {
	cin >> n ; 
	FOR(i,1,n) cin >> a[i] ; 
}

int calc(int l,int r) {
	if(l==r) return a[l] ; 
	int &val = dp[l][r] ; 
	if(val!=-1) return val ;
	val = 0 ; 	
	FOR(k,l+1,r-1) {
		maxi(val,calc(l,k) + calc(k,r) + a[l] * a[r] * a[k]) ;
	}
	return val ;
}	

void solve() {
	memset(dp,-1,sizeof dp) ; 
	a[0] = a[n+1] = 1 ;
	cout << calc(0,n+1) ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ; solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}