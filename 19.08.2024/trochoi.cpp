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

const int MAXN = 1e2 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

string s ; 
int n ;

void init() {
	cin >> s ; n = sz(s) ; s = "*" + s ; 
}

int dp[MAXN][3] ;
int can[MAXN][MAXN][3] ;

int Can(int l,int r,int t) {
	if(l==r) return (s[l] - 'a' == t) ; 
	if(can[l][r][t]!=-1) return can[l][r][t] ;
	int &val = can[l][r][t] ;
	val = 0 ; 
	int u , v ;
	if(t==0) u = 1 , v = 2 ; 
	if(t==1) u = 0 , v = 2 ; 
	if(t==2) u = 1 , v = 0 ; 
	FOR(k,l,r-1) {
		if(Can(l,k,u) && Can(k+1,r,v)) val = true ; 
		else if(Can(l,k,v) && Can(k+1,r,u)) val = true ; 
	}
	return val ;
}

void solve() {
	memset(can,-1,sizeof can) ;
	FOR(t,0,2) {
		FOR(i,1,n) {
			dp[i][t] = inf ; 
			FOR(j,1,i) if(Can(j,i,t)) mini(dp[i][t],dp[j-1][t]+1) ;
		}
	}
	cout << min({dp[n][0],dp[n][1],dp[n][2]}) << endl ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int test ; cin >> test ;
    while(test--) {
    	init() ; solve() ;
    }
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}