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

int n , k ;
int a[205] ;
int dp[205][205][1005] ;

void add(int &x,const int &y) {
    x+=y ; 
    if(x>=mod)x-=mod ;
}

int calc(int i,int j,int val) {
    if(j < 0) return 0 ;
    if(val > k) return 0 ;
    if(val < 0) return 0 ;
    if(i > n) return(j==0) ;
    int &res = dp[i][j][val] ; 
    if(res!=-1) return res ; 
    res = 0 ;
    int delta = a[i+1] - a[i] ;
    add(res,calc(i + 1 , j , val + j * delta) );
    add(res,calc(i + 1 , j , val + j * delta)*j%mod);
    add(res,calc(i + 1 , j + 1, val + (j + 1) * delta));
    add(res,calc(i + 1 , j - 1, val + (j - 1) * delta) * j%mod);
    return res ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    cin >> n >> k ; 
    FOR(i,1,n) cin >> a[i] ;
    sort(a+1,a+1+n) ;
    a[n+1] = 1e9 ;
    memset(dp,-1,sizeof dp) ;
    cout << calc(1,0,0) ;
    cout << endl ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}