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
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

string s , t ;
int n , m ;

void init(void) {
    cin >> s ;
    cin >> t ;
    //cout << s  << ' ' << t << endl ;
    n = sz(s) ; m = sz(t) ;
    s = "*" + s ; t = "*" + t ;
}

void process(void) {
    if(s==t) {
        cout << 0 ;
        return ; 
    }
    int x = 0 ; 
    int ans = 0 ; 
    FOR(i,1,n) {
        if(s[i]=='0' and t[i]=='1') {
            if(x<0) ans++ ;
            x++ ; 
        }else if(s[i] == '1' and t[i]=='0') {
            if(x>0) ans++ ;
            x-- ;
        }
    }
    if(x >= 0) {
        ans+=x ; 
        FOR(i,1,n) ans+=(s[i]=='?') ;
        cout << (ans == 0 ? - 1 : ans) ; 
        return ; 
    }
    FOR(i,1,n) {
        if(s[i]=='?' and t[i]=='1' and x<0) {
            ans+=2 ;
            x++ ; 
        }else if(s[i] == '?' and t[i] == '0') {
            ans++ ;
        }else if(s[i] == '?' and x==0) {
            ans++ ;
        }
    }
    if(x < 0) {
        cout << - 1 ;
        return ;
    }
    cout << (ans == 0 ? -1 :ans ) ;
}

signed main(void) {
    #define TASK "bits"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}