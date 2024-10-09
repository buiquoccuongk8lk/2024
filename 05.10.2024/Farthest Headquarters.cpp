/* 29 . 03 . 2008 */
#include <bits/stdc++.h>
using namespace std ;
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
#define MASK(a) (1ll << a)

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 3e5 + 5 ;

int n, n1, n2 ;
struct point {
    ll x, y ;
    int c ;
} P1[N], P2[N], H1[N], H2[N] ;

void init() {
    n1 = 0, n2 = 0 ;
    cin >> n ;
    FOR(i, 1, n) {
        int x, y, c ; cin >> x >> y >> c ;
        if(c == 0) P1[++n1] = {x, y, c} ;
        else P2[++n2] = {x, y, c} ;
    }
}

ll dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ;
}

ll ccw(point a, point b, point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - a.x) ;
}


void solve() {
    // build Google
    sort(P1 + 1, P1 + 1 + n1, [](point u, point v) {
         if(u.y == v.y) return u.x < v.x ;
         else return u.y < v.y ;
    }) ;

    sort(P1 + 2, P1 + 1 + n1, [](point A, point B) {
        if(ccw(P1[1], A, B) == 0) return dist(P1[1], A) < dist(P1[1], B) ;
        else return ccw(P1[1], A, B) > 0 ;
    }) ;

    H1[1] = P1[1] ;
    H2[1] = P1[1] ;
    P1[n1 + 1] = P1[1] ;

    int m1 = 2 ;
    FOR(i, 3, n1 + 1) {
        while(m1 >= 2 && ccw(H1[m1-1], H1[m1], P1[i]) > 0) m1-- ;
        H1[++m1] = P1[i] ;
    }

    H2[1] = P2[1] ;
    H2[2] = P2[2] ;
    H2[n2 + 1] = P2[1] ;

    int m2 = 2 ;
    FOR(i, 3, n2 + 1) {
        while(m2 >= 2 && ccw(H2[m2-1], H1[m2], P2[i]) > 0) m2-- ;
        H2[++m2] = P2[i] ;
    }

    ll ans = 0 ;
    FOR(i, 1, m1) FOR(j, 1, m2) {
        maxi(ans, dist(H1[i], H2[j])) ;
    }
    cout << (ll)sqrt(ans) << endl ;
}

signed main() {
    #define task "Farthest Headquarters"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ;
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    int tc ; cin >> tc ;
    FOR(LeThiThuVan, 1, tc) {
        init() ;
        solve() ;
    }
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
/* Watbor */
