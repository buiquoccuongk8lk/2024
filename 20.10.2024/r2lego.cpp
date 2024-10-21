/* 29 . 03 . 2008 */ 
#include <bits/stdc++.h>
using namespace std ;

bool watbor = 0 ;

typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;

#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n' 
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define uni(a) sort(all(a)), a.resize(unique(all(a))-a.begin()) 
#define MASK(a) (1ll << a) 

int gcd(int x, int y) {return __gcd(x, y) ;}
int lg(int x) {return __lg(x) ;}
int lcm(int x, int y) {return x / __gcd(x, y) * y ;}

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 5e3 + 5, M = 5e3 + 5, LG = __lg(N) + 1, base = 311 ;
const int oo = 2e9, sm = 1e9 + 7, mod1 = 1e9 + 7, mod2 = 998244353 ;
const long long inf = 1e18 ;

int n, k ; 

void init() {
    cin >> n >> k ; 
}

int dp[N][N] ;

void solve() {
    FOR(i, 1, n) dp[1][i] = 1 ; 

    FOR(i, 2, k) {
        FOR(j, 1, n) {
            FOR(t, 1, (n - j + 1) / 2) {
                if(j - i + 2 * t >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - i + 2 * t]) % sm ; 
            }

            FOR(t, 0, (n - i - j + 1) / 2) {
                if(j + i - 1 + 2 * t >= 0) 
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + i - 1 + 2 * t]) % sm ; 
            }
        }
    }

    int ans = 0 ;
    FOR(i, 1, k) FOR(j, 1, n) ans = (ans + dp[i][j]) % sm ;
    cout << ans ; 
}

int32_t main() {
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 

    #define task "r2lego"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; 
        freopen(task".out","w",stdout) ; 
    }

    int tc ; tc = 1 ;
    if(watbor) cin >> tc ;

    FOR(bqc, 1, tc) {
        init() ;
        return solve(), 0 ;
    }

    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */ 