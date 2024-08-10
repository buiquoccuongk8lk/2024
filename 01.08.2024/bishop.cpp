/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define         ll long long 
#define         fi first
#define         se second
#define         pb push_back
#define         ii pair<int,int>
#define         vii vector<ii>
#define         vi vector<int>
#define         endl '\n' 
#define         sz(a) (int)a.size()
#define         all(a) a.begin(),a.end()
#define         FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define         FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define         FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define         uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , m ; 
int a[1005][1005] ; 
ll D1[N] , D2[N] ; 

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n >> m ; 
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
    FOR(i,1,n)FOR(j,1,m) {
    	D1[i - j + 1000]+= a[i][j] ;
    }
    FOR(i,1,n)FOR(j,1,m) {
    	D2[i + j]+= a[i][j] ; 
    }
    ll ans = 0 ;
    FOR(i,1,n)FOR(j,1,m) {
    	ll sum = D1[i - j + 1000] + D2[i + j] - a[i][j] ;
    	ans = max(ans,sum) ; 
    }
    cout << ans ;
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}