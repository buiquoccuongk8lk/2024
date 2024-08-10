#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
#define tct template<class MITSURII,class CHANN>
#define pb push_back
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }
using namespace std ;
#define MAXN (int)1e6

const int mod = 1e9 + 7 ;

int x , y ;
// g[x] là kết quả bài toán
// f[x] số lượng dãy sao cho gcd(dãy) là bội của  x
// g[x] = f[x] - g[y] sao cho y là bội của x và y > x
int g[MAXN] , f[MAXN] , d[MAXN] ;
vector<int> D ; // chứa ước của i

int LT(int x,int y) {
    if(y==0) return 1 ;
    if(y==1) return x ;
    int c = LT(x,y/2) ;
    if(y&1) return c * c %mod * x %mod ;
    else return c * c % mod ;
}

void prepare() {
    FOR(i,1,sqrt(y)) {
        if(y % i == 0) {
            D.pb(i) ;
            D.pb(y/i) ;
        }
    }
    sort(D.begin(),D.end()) ;
    D.resize(unique(D.begin(),D.end())-D.begin()) ;
    reverse(D.begin(),D.end()) ;
}


signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    cin >> x >> y ;
    if(y%x!=0) {
        cout << 0 ;
        return 0 ;
    }
    prepare() ;
    while(!D.empty() && D.back() < x) D.pop_back() ;
    FOR(i,0,(int)D.size()-1) {
        f[i] = LT(2,y/D[i] - 1) ;
        FOR(j,0,i-1) if(D[j]%D[i]==0) {
            f[i] = (f[i] - f[j] + mod)%mod ;
        }
    }
    cout << f[D.size()-1] ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
