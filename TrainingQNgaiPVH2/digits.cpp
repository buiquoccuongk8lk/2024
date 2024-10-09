/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

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
const long long MOD = 1e9 + 19972207 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
tct void add(WORK &x, const HARD &y) {x+=y ; x%=MOD ; }
int n , k , p ;
string s ;

void init(void) {
    cin >> n >> k >> p ;
    cin >> s ; 
    s = '*' + s ;
}

namespace sub1 {

    ll dp[5005][205] ;
    ll digits[5005][5005] ;

    ll calc(int i,int j) {
        return digits[i][j] ;
    }

    void solve(void) {

        FOR(i,1,n) FOR(j,1,n) digits[i][j]=(digits[i][j-1]*10+(s[j]-'0'))%p;
        
        dp[0][0] = 1 ;

        FOR(i,1,n) FOR(j,1,min(i,k)) {
            FOR(v,1,i) {
                if(calc(v,i)%p==0) {
               //     cout << v-1 << ' ' << j -1 << endl ;
                    add(dp[i][j],dp[v-1][j-1]) ; 
                }
            }
        }

       /* FOR(i,1,n) FOR(j,1,k) {
            cout << i << ' ' << j << ' ' << dp[i][j] << endl ;
        }*/

        cout << dp[n][k] ;
    }

}

namespace sub2 {
    
    ll LT(ll x,ll y) {
        if(y==0) return 1 ;
        if(y==1) return x ; 
        ll c = LT(x,y/2) ; 
        if(y&1) return c * c%MOD * x%MOD ; 
        else return c*c%MOD ;
    }

    ll fact[N] ;

    ll mul(ll a,ll b) {
        return (a*b)%MOD ; 
    }

    ll C(int n,int k) {
        return mul( fact[n] , LT(mul(fact[n-k],fact[k]),MOD-2) ) ; 
    }

    void solve(void) {
        fact[0] = 1 ; 
        FOR(i,1,n) fact[i] = (fact[i-1]*i)%MOD ; 
        cout << C(n-1,k-1) ; 
    }

}

namespace sub3 {

    ll LT(ll x,ll y) {
        if(y==0) return 1 ;
        if(y==1) return x ; 
        ll c = LT(x,y/2) ; 
        if(y&1) return c * c%MOD * x%MOD ; 
        else return c*c%MOD ;
    }

    ll fact[N] ;

    ll mul(ll a,ll b) {
        return (a*b)%MOD ; 
    }

    ll C(int n,int k) {
        return mul( fact[n] , LT(mul(fact[n-k],fact[k]),MOD-2) ) ; 
    }

    void solve(void) {
        int cnt = 0 ; 
        FOR(i,1,n) cnt+=((s[i]-'0')%2==0) ; 
        fact[0] = 1 ; 
        FOR(i,1,n) fact[i] = (fact[i-1]*i)%MOD ; 
        if((s[n]-'0')%2!=0) {
            cout << 0 ; 
        }else {
            cout << C(cnt-1,k-1) ;
        }
    }   

}

namespace sub4 {


    ll LT(ll x,ll y) {
        if(y==0) return 1 ;
        if(y==1) return x ; 
        ll c = LT(x,y/2) ; 
        if(y&1) return c * c%MOD * x%MOD ; 
        else return c*c%MOD ;
    }

    ll fact[N] ;

    ll mul(ll a,ll b) {
        return (a*b)%MOD ; 
    }

    ll C(int n,int k) {
        return mul( fact[n] , LT(mul(fact[n-k],fact[k]),MOD-2) ) ; 
    }
    int pre[N] ;

    void solve(void) {
        FOR(i,1,n) pre[i] = (pre[i-1] + s[i] - '0')%3 ; 
        if(pre[n]!=0) {
            cout << 0 ;
            return ; 
        }
        int cnt = 0 ;
        fact[0] = 1 ; 
        FOR(i,1,n) fact[i] = (fact[i-1]*i)%MOD ; 
        FOR(i,1,n-1) cnt+=(pre[i]==0) ;
        cout << C(cnt,k-1) ; 
    }

}

namespace sub5 {
    ll LT(ll x,ll y) {
        if(y==0) return 1 ;
        if(y==1) return x ; 
        ll c = LT(x,y/2) ; 
        if(y&1) return c * c%MOD * x%MOD ; 
        else return c*c%MOD ;
    }

    ll fact[N] ;

    ll mul(ll a,ll b) {
        return (a*b)%MOD ; 
    }

    ll C(int n,int k) {
        return mul( fact[n] , LT(mul(fact[n-k],fact[k]),MOD-2) ) ; 
    }
    ll pre[N] ;
    
    void solve(void) {
        FOR(i,1,n) pre[i] = (pre[i-1]*10 + s[i] - '0')%p ;
        if(pre[n]!=0) {
            cout << 0 ;
            return ; 
        }
        int cnt = 0 ;
        fact[0] = 1 ; 
        FOR(i,1,n) fact[i] = (fact[i-1]*i)%MOD ; 
        FOR(i,1,n-1) cnt+=(pre[i]==0) ;
        cout << C(cnt,k-1) ; 
    }

}

signed main(void) {
    #define TASK "digits"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    /*if( n <= 500 and k <= 20 ) sub1::solve() ;
    else if( p == 1 ) sub2::solve() ;
    else if( p == 2 ) sub3::solve() ; 
    else if( p == 3 ) sub4::solve() ; 
    else */sub5::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}