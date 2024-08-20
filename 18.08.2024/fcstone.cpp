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

const int MAXN = 1e5 + 5 ;
const int mod = 1e9 + 7 ; 
const ll inf = 1e18 ; 
const int oo = 2e9 ; 

int n , L , R ;
int a[2005] ; 
int dp[2005][2005] ;
int f[2005] ;
int pre[2005] ;

int solve1(int k,int limit) {
	FOR(i,0,n)FOR(j,0,n) dp[i][j] = 0 ;
	dp[0][0] = 1 ; 
	FOR(i,1,n) FOR(j,1,R) FOR(v,1,i) {
		if(  ( ( (pre[i] - pre[v-1]) | limit ) >> k ) == (limit >> k) && dp[v-1][j-1]) dp[i][j] = 1 ;
	}
	FOR(j,L,R) if(dp[n][j]) return 1 ;
	return 0 ;
}

int solve2(int k,int limit) {
	FOR(i,1,n) f[i] = inf ;
	f[0] = 0 ; 
	FOR(i,1,n) FOR(j,1,i) {
		 if ((((pre[i] - pre[j - 1]) | limit) >> k) == (limit >> k)) mini(f[i],f[j-1]+1) ;
	}
	return f[n] <= R ; 
}

int ok(int k,int limit) {
	if(L==1) return solve2(k,limit) ; 
	return solve1(k,limit) ; 
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> L >> R ; 
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;  
    int ans = 0 ;
    FORD(k,62,0) if(!ok(k,ans)) ans|= (1ll<<k) ; 
    cout << ans ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}