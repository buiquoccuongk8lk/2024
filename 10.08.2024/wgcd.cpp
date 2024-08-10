#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
#define tct template<class MITSURII,class CHANN>
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ;
#define MAXN 200005

int n ;
int a[MAXN] ;
int f[MAXN] ;// so luong cap boi cua x
int g[MAXN] ;// so luong cap co __gcd(ai,aj) = x
int d[MAXN] ;// so luong boi so cua x
int cnt[MAXN] ;

void prepare() {
    FOR(i,1,n) cnt[a[i]]++ ;
    int mx = *max_element(a+1,a+1+n) ;
    FOR(i,1,mx) {
        for(int j = i ; j <= mx ; j+=i) d[i]+= cnt[j] ;
    }
    FOR(i,1,mx) f[i] = d[i] * (d[i]-1)/2 ;
    FOR(i,1,mx) g[i] = f[i] ;
    FORD(i,mx,1) {
        for(int j = 2 * i ; j <= mx ; j+=i) {
            g[i]-= g[j] ;
        }
    }
}

void solve() {
    prepare() ;
    long long sum = 0 ;
    int mx = *max_element(a+1,a+1+n) ;
    FOR(i,1,mx) sum+= g[i] * i ;
    cout << sum ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    cin >> n ;
    FOR(i,1,n) cin >> a[i] ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
